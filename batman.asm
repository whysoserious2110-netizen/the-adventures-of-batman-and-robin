; ============================================================
;  BATMAN.ASM  -  THE ADVENTURES OF BATMAN & ROBIN
;  PHASE 0 : Title screen + OPTION MODE + Batcave cutscene
;  STEP 2  : scrolling street + Batman run (A/S or arrows, ESC)
;  TASM 5.1  |  VGA mode 13h (320x200, 256 colors)
;
;  Needs in the same folder:  ALFRED.INC  (assembled in)
;                             TITLE.BIN   (loaded at run time)
;
;  Title:  UP/DOWN = choose, ENTER/SPACE = select, ESC = quit
;  Option: UP/DOWN = choose, LEFT/RIGHT/ENTER = change, ESC = back
;  Cutscene: ENTER/SPACE = next page, ESC = skip
; ============================================================
.286
.MODEL SMALL
.STACK 200h
JUMPS

; ---------------- monitor / speaker ids -------------------
M_BLACK   EQU 0
M_HARLEY  EQU 1
M_JOKER   EQU 2
M_PARK    EQU 3
M_PARKH   EQU 4
M_STATIC  EQU 5
M_EQUIP   EQU 6

S_NONE    EQU 0
S_ALFRED  EQU 1
S_BRUCE   EQU 2
S_HARLEY  EQU 3
S_JOKER   EQU 4
S_BATMAN  EQU 5

; ---------------- title slide-in speed (slow motion) ------
SLIDE_STEP  EQU 1           ; rows moved per step
SLIDE_DELAY EQU 2           ; vsync frames per step (bigger = slower)

; ---------------- macros ----------------------------------
; filled rectangle: x, y, width, height, color
RECTF MACRO px,py,pw,ph,pc
    mov ax,px
    mov bx,py
    mov cx,pw
    mov dx,ph
    mov si,pc
    call FillRect
ENDM

; filled triangle (apex up): center x, top y, height, slope shift, color
TRIANG MACRO px,py,ph,psh,pc
    mov ax,px
    mov bx,py
    mov cx,ph
    mov dx,psh
    mov si,pc
    call TriUp
ENDM

; beveled frame: x, y, w, h, light color, dark color
BEVEL MACRO px,py,pw,ph,pl,pd
    mov ax,px
    mov bx,py
    mov cx,pw
    mov dx,ph
    mov si,pl
    mov di,pd
    call Bevel
ENDM

; small screw / rivet
RIVET MACRO px,py
    RECTF px,py,3,3,12
    RECTF px,py,2,2,46
ENDM

; round glossy lamp: x, y, color
LAMP MACRO px,py,pc
    RECTF px,py+1,8,6,12
    RECTF px+1,py,6,8,12
    RECTF px+1,py+1,6,6,pc
    RECTF px+2,py+2,2,2,1
ENDM

; ============================================================
.DATA
; ============================================================
bufseg    dw 0              ; off-screen buffer segment (title picture)
drawseg   dw 0A000h         ; where the draw routines write
font_seg  dw 0              ; ROM 8x8 font pointer
font_off  dw 0
txt_x     dw 0
txt_y     dw 0
txt_sc    dw 1              ; text scale
txt_col   dw 1              ; text color
glyph     db 8 dup(0)
g_row     dw 0
g_col     dw 0
g_bits    db 0
t_cx      dw 0              ; triangle variables
t_y       dw 0
t_h       dw 0
t_sh      dw 0
t_col     dw 0
t_r       dw 0
c_dy      dw 0              ; circle variable
lp        dw 0              ; general loop counter
bv_x      dw 0              ; bevel variables
bv_y      dw 0
bv_w      dw 0
bv_h      dw 0
bv_l      dw 0
bv_d      dw 0
seed      dw 1234h
blink     dw 0
curmon    db 0FFh           ; monitor currently shown
skipf     db 0              ; 1 = skip cutscene
fastf     db 0              ; 1 = show text instantly
spk       db 0
noise_tab db 0,12,3,1       ; static colors

; ---------------- palette (R,G,B 0..63) -------------------
palA label byte             ; colors 0..15
    db  0, 0, 0             ; 0  black
    db 63,63,63             ; 1  white
    db 60,46, 6             ; 2  gold
    db 44,44,48             ; 3  light gray
    db  6, 8,24             ; 4  navy background
    db 10,14,36             ; 5  navy mid
    db 14,20,52             ; 6  navy light line
    db 28,18,16             ; 7  brown frame
    db 40,28,26             ; 8  brown light
    db  4,26, 8             ; 9  green light
    db 50,22, 8             ; 10 orange light
    db 14,14,18             ; 11 speaker gray
    db  8, 8,12             ; 12 dark gray
    db 44,44,60             ; 13 lavender (text)
    db 52, 6, 8             ; 14 red
    db 60,50,38             ; 15 skin
palB label byte             ; colors 32..47
    db 34,10,40             ; 32 purple suit
    db 10,44,10             ; 33 green hair
    db  8, 0, 0             ; 34 sky 1
    db 16, 1, 1             ; 35 sky 2
    db 24, 2, 2             ; 36 sky 3
    db 32, 3, 3             ; 37 sky 4
    db 14,16,40             ; 38 fence blue
    db 50,50,52             ; 39 spotlight
    db 12, 3,16             ; 40 stage floor
    db 14,12,34             ; 41 batman cowl
    db 30,22, 8             ; 42 tan background
    db 24,10,30             ; 43 purple background
    db  3, 4,15             ; 44 deep navy (top of console)
    db 16, 9, 8             ; 45 dark brown (panel shadow)
    db 52,44,40             ; 46 metal highlight
    db 20,26,56             ; 47 blue edge glow
    INCLUDE ALFRED.INC      ; palC (colors 48..63) + alf_img bitmap
    INCLUDE BRUCE.INC       ; palE (colors 64..79 in the cutscene) + bruce_img
    INCLUDE HARLEY.INC      ; palF (colors 80..95 in the cutscene) + harley_img
    INCLUDE JOKER.INC       ; palG (colors 96..111) + joker_img
    INCLUDE JOKERTV.INC     ; palH (colors 112..127) + jokertv_img
    INCLUDE BATPORT.INC     ; palI (colors 128..143) + batman_img
    INCLUDE EQUIP.INC       ; palJ (colors 144..159) + equip_img
    INCLUDE STAGE.INC       ; sprite table + constants (colors 64..255 from STAGE.BIN)
palbuf    db 256*3 dup(0)   ; working palette (colors 0..255)

; ---------------- strings ---------------------------------
sT1    db "the adventures of",0
sT2    db "BATMAN & ROBIN",0
sStart db "GAME START",0
sPh1   db "PHASE 1 - GAMEPLAY GOES HERE",0
sPh2   db "PRESS ANY KEY TO EXIT",0
msgmem db "Not enough memory.$"
fname   db "TITLE.BIN",0
fname2  db "OPTION.BIN",0
fname3  db "AMUSED.BIN",0
msgfile db "TITLE.BIN, OPTION.BIN or AMUSED.BIN not found.$"
fname5   db "STAGE.BIN",0
msgstage db "STAGE.BIN not found or not enough memory.$"
gamepal  db 576 dup(0)          ; palette of STAGE.BIN (colors 64..255)
stseg    dw 5 dup(0)            ; 5 street screens (64000 bytes each)
atlseg   dw 0                   ; sprite atlas segment
cam_x    dw 0                   ; camera (world x of the left screen edge)
wx       dw 0                   ; Batman world x
hp       dw 0                   ; health bar height
anim_f   db 0
anim_t   db 0
moving   db 0
k_left   db 0
k_right  db 0
k_a      db 0
k_s      db 0
k_esc    db 0
old9_off dw 0
old9_seg dw 0
bat_dir  db 0                   ; 0 = facing right, 1 = facing left
score    dw 0
scorestr db "00000",0
sp_w     dw 0
sp_h     dw 0
bufseg2  dw 0                   ; off-screen buffer for the option background
titlepal db 576 dup(0)          ; palette of TITLE.BIN  (colors 64..255)
optpal   db 576 dup(0)          ; palette of OPTION.BIN (colors 64..255)

; ---------------- title menu + option mode ----------------
sOption  db "OPTION",0
sOpTitle db "OPTION MODE",0
sOpLevel db "LEVEL",0
sOpCtrl  db "CONTROL",0
sOpMusic db "MUSIC",0
sOpSound db "SOUND MODE",0
sOpExit  db "START TO EXIT",0
sOpHint  db "UP/DOWN:SELECT  LEFT/RIGHT:CHANGE",0
sNormal  db "NORMAL",0
sHard    db "HARD",0
sOn      db "ON",0
sOff     db "OFF",0
sStereo  db "STEREO",0
sMono    db "MONO",0
cBack    db "BACK",0
cFwd     db "FORWARD",0
cJump    db "JUMP",0
cPunch   db "PUNCH",0
cItem    db "ITEM",0
cGuard   db "GUARD",0
kBack    db "A",0
kFwd     db "S",0
kJump    db "SPACE",0
kPunch   db "J",0
kItem    db "D",0
kGuard   db "K",0
menusel  db 0
optsel   db 0
opt_level  db 0                 ; 0 = NORMAL, 1 = HARD
opt_music  db 1                 ; 0 = OFF, 1 = ON
opt_sound  db 1                 ; 0 = MONO, 1 = STEREO
oplab   dw offset sOpLevel,offset sOpMusic,offset sOpSound
row_y   dw 30,128,142,160
lvl_tab dw offset sNormal,offset sHard
mus_tab dw offset sOff,offset sOn
snd_tab dw offset sMono,offset sStereo
ctl_tab dw offset cBack,offset kBack
        dw offset cFwd,offset kFwd
        dw offset cJump,offset kJump
        dw offset cPunch,offset kPunch
        dw offset cItem,offset kItem
        dw offset cGuard,offset kGuard

lAlfred db "ALFRED",0
lBruce  db "BRUCE W.",0
lHarley db "HARLEY.Q",0
lJoker  db "THE JOKER",0
lBatman db "BATMAN",0
; label offset, label x  (indexed by speaker id - 1)
spk_tab dw offset lAlfred,21
        dw offset lBruce,13
        dw offset lHarley,13
        dw offset lJoker,9
        dw offset lBatman,21

tEmpty db 0
t1a  db "Master Bruce,",0
t1b  db "we've picked up",0
t2a  db "a suspicious",0
t2b  db "sounding broadcast.",0
t3a  db "Okay. Put it on",0
t3b  db "the monitor.",0
t4a  db "Hello, hello. This is",0
t4b  db "The Joker Channel.",0
t5a  db "And now for an urgent",0
t5b  db "message from",0
t6a  db "The Joker himself.",0
t6b  db "Here...he...is...",0
t7a  db "Are you watching,",0
t7b  db "Batman? I've prepared",0
t8a  db "Gotham City Amusement",0
t8b  db "Park just for all",0
t9a  db "those good little boys",0
t9b  db "and girls of Gotham City.",0
t10a db "Tomorrow is a real",0
t10b db "'scream' if you know",0
t11a db "what I mean.",0
t11b db "Ha Ha Ha Ha!",0
t12a db "Well, everyone, thanks",0
t12b db "for watching",0
t13a db "The Joker Channel. See",0
t13b db "you next time. Bye.",0
t14a db "Master Bruce, this is",0
t14b db "undoubtedly a trap of",0
t15a db "some kind.",0
t16a db "I know, Alfred. But",0
t16b db "I still have to go.",0
t17a db "Quickly! Prepare the",0
t17b db "equipment!",0
t18a db "Of course,",0
t18b db "Master Bruce.",0

; ---------------- story script ----------------------------
; record = monitor, speaker, auto-frames (0 = wait key), line1, line2
script label byte
    db M_BLACK,S_ALFRED
    dw 0,offset t1a,offset t1b
    db M_BLACK,S_ALFRED
    dw 0,offset t2a,offset t2b
    db M_BLACK,S_BRUCE
    dw 0,offset t3a,offset t3b
    db M_HARLEY,S_HARLEY
    dw 0,offset t4a,offset t4b
    db M_HARLEY,S_HARLEY
    dw 0,offset t5a,offset t5b
    db M_HARLEY,S_HARLEY
    dw 0,offset t6a,offset t6b
    db M_JOKER,S_JOKER
    dw 0,offset t7a,offset t7b
    db M_JOKER,S_JOKER
    dw 0,offset t8a,offset t8b
    db M_JOKER,S_JOKER
    dw 0,offset t9a,offset t9b
    db M_JOKER,S_JOKER
    dw 0,offset t10a,offset t10b
    db M_JOKER,S_JOKER
    dw 0,offset t11a,offset t11b
    db M_PARK,S_NONE                    ; amusement park image (auto)
    dw 80,offset tEmpty,offset tEmpty
    db M_PARKH,S_HARLEY
    dw 0,offset t12a,offset t12b
    db M_PARKH,S_HARLEY
    dw 0,offset t13a,offset t13b
    db M_STATIC,S_NONE                  ; TV static (auto)
    dw 60,offset tEmpty,offset tEmpty
    db M_BLACK,S_ALFRED
    dw 0,offset t14a,offset t14b
    db M_BLACK,S_ALFRED
    dw 0,offset t15a,offset tEmpty
    db M_BLACK,S_BATMAN
    dw 0,offset t16a,offset t16b
    db M_BLACK,S_BATMAN
    dw 0,offset t17a,offset t17b
    db M_BLACK,S_ALFRED
    dw 0,offset t18a,offset t18b
    db M_EQUIP,S_NONE                   ; equipment on the monitor (auto)
    dw 200,offset tEmpty,offset tEmpty
    db 0FFh                             ; end of script       ; end of script

; ============================================================
.CODE
; ============================================================
start:
    mov ax,@data
    mov ds,ax

    ; shrink our memory block, then allocate a 64000-byte buffer
    mov bx,1000h
    mov ah,4Ah                  ; ES = PSP at program start
    int 21h
    mov bx,0FA0h                ; 4000 paragraphs = 64000 bytes
    mov ah,48h
    int 21h
    jc no_mem
    mov [bufseg],ax
    mov bx,0FA0h                ; second 64000-byte buffer (option background)
    mov ah,48h
    int 21h
    jc no_mem
    mov [bufseg2],ax

    ; pointer to the ROM 8x8 font
    mov ax,1130h
    mov bh,3
    int 10h
    mov [font_seg],es
    mov [font_off],bp

    mov ax,13h                  ; VGA mode 13h
    int 10h

    call InitPal
    mov al,32
    call SetPal

    mov dx,offset fname2        ; OPTION.BIN -> second buffer
    mov si,offset optpal
    mov ax,[bufseg2]
    call LoadBin

    ; ---------- 1) TITLE SCREEN ----------
    call DrawTitle              ; loads TITLE.BIN into the buffer
    call SlideTitle             ; slide up from the bottom to center
    mov word ptr [drawseg],0A000h
    mov word ptr [blink],0
    mov byte ptr [menusel],0

title_wait:
    inc word ptr [blink]
    call DrawMenu
    call WaitVsync
    mov ah,1
    int 16h
    jz title_wait
    xor ah,ah
    int 16h
    cmp ah,1                    ; ESC = quit
    je quit
    cmp ah,48h                  ; UP
    je t_flip
    cmp ah,50h                  ; DOWN
    je t_flip
    cmp al,13                   ; ENTER
    je t_enter
    cmp al,' '                  ; SPACE
    je t_enter
    jmp title_wait
t_flip:
    xor byte ptr [menusel],1
    jmp title_wait
t_enter:
    cmp byte ptr [menusel],0
    je t_go
    call OptionMode
    jmp title_wait

    ; ---------- 2) STORY CUTSCENE ----------
t_go:
    call FadeOut
    call ShowAmused             ; "Amused to Death" card, then the story
    call UseBrucePal
    call UseHarleyPal
    call UseJokerPal            ; new
    call UseJokerTvPal
    call UseBatmanPal
    call UseEquipPal            ; new
    mov word ptr [drawseg],0A000h
    RECTF 0,0,320,200,0
    call DrawConsole
    mov byte ptr [curmon],0FFh
    mov byte ptr [skipf],0
    call FadeIn

    mov di,offset script
cs_loop:
    cmp byte ptr [di],0FFh
    je cs_done
    mov al,[di]                 ; monitor id
    cmp al,[curmon]
    je cs_same
    mov [curmon],al
    call DrawMonitor
cs_same:
    mov al,[di+1]               ; speaker id
    call DrawPortrait
    RECTF 86,148,226,48,0       ; clear text box
    mov cx,[di+2]               ; auto frames?
    or cx,cx
    jz cs_type
    call AutoWait
    jmp cs_chk
cs_type:
    mov bx,[di+4]
    mov dx,[di+6]
    call TypeLines
    cmp byte ptr [skipf],1
    je cs_done
    xor ah,ah                   ; wait for a key
    int 16h
    cmp ah,1
    jne cs_chk
    mov byte ptr [skipf],1
cs_chk:
    cmp byte ptr [skipf],1
    je cs_done
    add di,8
    jmp cs_loop

cs_done:
    call FadeOut
    mov word ptr [drawseg],0A000h
    RECTF 0,0,320,200,0
    call StartGame              ; placeholder for the gameplay (Phase 1)

quit:
    mov ax,3                    ; back to text mode
    int 10h
    mov ax,4C00h
    int 21h

no_mem:
    mov dx,offset msgmem
    mov ah,9
    int 21h
    mov ax,4C01h
    int 21h

; ============================================================
;  STARTGAME - Phase 1: scrolling street, Batman runs
;  A / S or LEFT / RIGHT = move, ESC = leave the stage
;  Needs STAGE.BIN + STAGE.INC (street 1600x200 + sprite atlas)
; ============================================================
SPEED     EQU 8                 ; pixels per frame (bigger = faster)
WORLD_W   EQU 1600
START_WX  EQU 70                ; Batman starts here (world x)
CAM_LEAD  EQU 140               ; camera starts moving when Batman passes this screen x
CAM_MAX   EQU WORLD_W-320
MIN_SX    EQU 30                ; Batman cannot walk left of this screen x
MAX_WX    EQU WORLD_W-30
ANIM_RATE EQU 1                 ; frames per animation step (bigger = slower)

StartGame proc near
    ; free the option background buffer to make room
    mov ax,[bufseg2]
    mov es,ax
    mov ah,49h
    int 21h
    call LoadStage
    jc sg_nofile
    call UseGamePal
    mov word ptr [drawseg],0A000h
    mov word ptr [cam_x],0
    mov word ptr [wx],START_WX
    mov byte ptr [bat_dir],0
    mov byte ptr [anim_f],0
    mov byte ptr [anim_t],0
    mov word ptr [score],0
    mov word ptr [hp],TUBE_H
    mov byte ptr [k_left],0
    mov byte ptr [k_right],0
    mov byte ptr [k_a],0
    mov byte ptr [k_s],0
    mov byte ptr [k_esc],0
    call InstallKbd
    call RenderGame
    mov ax,[bufseg]
    call CopyBuf
    call FadeIn
sg_loop:
    cmp byte ptr [k_esc],0
    jne sg_exit
    mov byte ptr [moving],0
    ; ---- right ----
    mov al,[k_right]
    or al,[k_s]
    jz sg_chkl
    mov byte ptr [bat_dir],0
    mov byte ptr [moving],1
    mov ax,[wx]
    add ax,SPEED
    cmp ax,MAX_WX
    jbe sg_rok
    mov ax,MAX_WX
sg_rok:
    mov [wx],ax
    jmp sg_cam
    ; ---- left ----
sg_chkl:
    mov al,[k_left]
    or al,[k_a]
    jz sg_cam
    mov byte ptr [bat_dir],1
    mov byte ptr [moving],1
    mov ax,[wx]
    sub ax,SPEED
    mov bx,MIN_SX               ; left limit = start of the street
    cmp ax,bx
    jge sg_lok
    mov ax,bx
sg_lok:
    mov [wx],ax
    ; ---- camera follows Batman both ways ----
sg_cam:
    mov ax,[wx]
    sub ax,CAM_LEAD
    jge sg_c1
    xor ax,ax
sg_c1:
    cmp ax,CAM_MAX
    jbe sg_cset
    mov ax,CAM_MAX
sg_cset:
    mov [cam_x],ax
sg_noscr:
    ; ---- run animation ----
    cmp byte ptr [moving],0
    jne sg_anim
    mov byte ptr [anim_f],0
    mov byte ptr [anim_t],0
    jmp sg_draw
sg_anim:
    inc byte ptr [anim_t]
    cmp byte ptr [anim_t],ANIM_RATE
    jb sg_draw
    mov byte ptr [anim_t],0
    inc byte ptr [anim_f]
    cmp byte ptr [anim_f],NRUN
    jb sg_draw
    mov byte ptr [anim_f],0
sg_draw:
    call RenderGame
    call WaitVsync
    mov ax,[bufseg]
    call CopyBuf
    jmp sg_loop
sg_exit:
    call RestoreKbd
    call FadeOut
    ret
sg_nofile:
    mov ax,3
    int 10h
    mov dx,offset msgstage
    mov ah,9
    int 21h
    mov ax,4C01h
    int 21h
StartGame endp

; ---- allocate buffers and read STAGE.BIN (carry set = failed) ----
; file: 576 palette bytes, 5 x 64000 street (5 screens side by side),
;       then the 62400-byte sprite atlas (320 wide)
LoadStage proc near
    push ax
    push bx
    push cx
    push dx
    push si
    xor si,si
ls_al:
    mov bx,0FA0h                ; 64000 bytes
    mov ah,48h
    int 21h
    jc ls_fail
    mov [stseg+si],ax
    add si,2
    cmp si,10
    jb ls_al
    mov bx,3901                 ; atlas
    mov ah,48h
    int 21h
    jc ls_fail
    mov [atlseg],ax
    mov dx,offset fname5
    mov ax,3D00h
    int 21h
    jc ls_fail
    mov bx,ax                   ; file handle
    mov dx,offset gamepal
    mov cx,576
    mov ah,3Fh
    int 21h
    xor si,si
ls_rd:
    push ds
    mov ax,[stseg+si]
    mov ds,ax
    xor dx,dx
    mov cx,64000
    mov ah,3Fh
    int 21h
    pop ds
    add si,2
    cmp si,10
    jb ls_rd
    push ds
    mov ax,[atlseg]
    mov ds,ax
    xor dx,dx
    mov cx,62400
    mov ah,3Fh
    int 21h
    pop ds
    mov ah,3Eh                  ; close
    int 21h
    clc
    jmp ls_x
ls_fail:
    stc
ls_x:
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret
LoadStage endp

; ---- stage colors (64..255) into the working palette ----
UseGamePal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset gamepal
    mov di,offset palbuf+192
    mov cx,288
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseGamePal endp

; ---- keyboard: our own INT 9 so held keys work ----
InstallKbd proc near
    push ax
    push bx
    push dx
    push ds
    push es
    mov ax,3509h
    int 21h
    mov [old9_off],bx
    mov [old9_seg],es
    push cs
    pop ds
    mov dx,offset KbdISR
    mov ax,2509h
    int 21h
    pop es
    pop ds
    pop dx
    pop bx
    pop ax
    ret
InstallKbd endp

RestoreKbd proc near
    push ax
    push dx
    push ds
    mov dx,[old9_off]
    mov ax,[old9_seg]
    mov ds,ax
    mov ax,2509h
    int 21h
    pop ds
    pop dx
    pop ax
    ret
RestoreKbd endp

KbdISR proc far
    push ax
    push bx
    push ds
    mov ax,@data
    mov ds,ax
    in al,60h
    mov bl,al
    and bl,7Fh                  ; scan code
    mov ah,1                    ; 1 = key down
    test al,80h
    jz kb_set
    xor ah,ah                   ; 0 = key released
kb_set:
    cmp bl,4Bh
    jne kb_1
    mov [k_left],ah
kb_1:
    cmp bl,4Dh
    jne kb_2
    mov [k_right],ah
kb_2:
    cmp bl,1Eh
    jne kb_3
    mov [k_a],ah
kb_3:
    cmp bl,1Fh
    jne kb_4
    mov [k_s],ah
kb_4:
    cmp bl,01h
    jne kb_5
    mov [k_esc],ah
kb_5:
    mov al,20h                  ; end of interrupt
    out 20h,al
    pop ds
    pop bx
    pop ax
    iret
KbdISR endp

; ---- build one frame in the back buffer (bufseg) ----
RenderGame proc near
    pusha
    call BuildStreet
    mov ax,[bufseg]
    mov [drawseg],ax            ; text / rectangles go to the back buffer
    mov ax,[wx]
    sub ax,[cam_x]              ; Batman's screen x
    xor bx,bx                   ; idle
    cmp byte ptr [moving],0
    je rg_spr
    mov bl,[anim_f]
    inc bx                      ; run sprites start at index 1
rg_spr:
    mov dl,[bat_dir]
    call DrawAtlasSpr
    call DrawHud
    mov word ptr [drawseg],0A000h
    popa
    ret
RenderGame endp

; ---- copy the visible 320 columns of the street into the back buffer ----
BuildStreet proc near
    pusha
    push ds
    push es
    cld
    mov ax,[bufseg]
    mov es,ax
    mov ax,[cam_x]
    xor dx,dx
    mov cx,320
    div cx                      ; ax = screen number, dx = offset inside it
    shl ax,1
    mov bx,ax
    push word ptr [stseg+bx+2]  ; next screen (only used when dx <> 0)
    mov ax,[stseg+bx]
    mov ds,ax
    mov bp,320
    sub bp,dx                   ; bp = bytes taken from the first screen
    mov si,dx
    xor di,di
    mov ax,200
bs_a:
    mov cx,bp
    rep movsb
    add si,dx
    add di,dx
    dec ax
    jnz bs_a
    pop ax                      ; segment of the next screen
    or dx,dx
    jz bs_done
    mov ds,ax
    xor si,si
    mov di,bp
    mov ax,200
bs_b:
    mov cx,dx
    rep movsb                   ; copy the left part of the next screen
    add si,bp                   ; next source row
    add di,bp                   ; next dest row, past the part already filled
    dec ax
    jnz bs_b
bs_done:
    pop es
    pop ds
    popa
    ret
BuildStreet endp

; ---- atlas sprite into the back buffer ----
;      AX = anchor screen x, BX = sprite number, DL = 1 to mirror
;      (transparent color 0, clipped left/right)
DrawAtlasSpr proc near
    pusha
    push ds
    push es
    cld
    push ax                     ; anchor x
    push dx                     ; flip flag in dl
    mov ax,bx
    mov cx,12                   ; 6 words per sprite
    mul cx
    mov bx,ax                   ; bx = table offset
    pop dx
    pop ax
    mov cx,[spr_tab+bx+8]       ; anchor inside the sprite
    or dl,dl
    jz da_nf
    mov cx,[spr_tab+bx+4]
    dec cx
    sub cx,[spr_tab+bx+8]       ; w-1-anchor when mirrored
da_nf:
    sub ax,cx                   ; ax = left edge on screen
    mov bp,1
    or dl,dl
    jz da_s
    mov bp,-1                   ; mirrored: write right to left
    add ax,[spr_tab+bx+4]
    dec ax
da_s:                           ; ax = screen x of the first column drawn
    mov dx,[spr_tab+bx+10]      ; screen y
    mov di,dx
    shl di,6
    shl dx,8
    add di,dx
    add di,ax                   ; di = y*320 + x
    mov dx,[spr_tab+bx+2]       ; atlas y
    mov si,dx
    shl si,6
    shl dx,8
    add si,dx
    add si,[spr_tab+bx+0]       ; si = atlas y*320 + atlas x
    mov dx,[spr_tab+bx+6]       ; rows
    mov cx,[spr_tab+bx+4]       ; width (< 256)
    mov bx,ax                   ; bx = current screen x
    mov ah,cl                   ; ah = width
    push ax
    mov ax,[bufseg]
    mov es,ax
    mov ax,[atlseg]
    mov ds,ax
    pop ax
da_row:
    push di
    push bx
    mov cl,ah
da_px:
    lodsb
    or al,al
    jz da_skip
    cmp bx,320
    jae da_skip                 ; off screen (also catches negative x)
    mov es:[di],al
da_skip:
    add di,bp
    add bx,bp
    dec cl
    jnz da_px
    pop bx
    pop di
    add di,320
    mov cl,ah
    sub si,cx                   ; back to the start of this atlas row
    add si,320                  ; next atlas row
    dec dx
    jnz da_row
    pop es
    pop ds
    popa
    ret
DrawAtlasSpr endp

; ---- HUD: BATMAN flag, orange health bar, 5-digit score ----
DrawHud proc near
    pusha
    mov ax,HUD_X
    mov bx,SPR_HUD
    xor dl,dl
    call DrawAtlasSpr
    mov dx,[hp]                 ; health bar: fills from the bottom
    or dx,dx
    jz dh_noh
    mov bx,TUBE_Y+TUBE_H
    sub bx,dx
    mov ax,TUBE_X
    mov cx,TUBE_W
    mov si,HEALTH_COL
    call FillRect
dh_noh:
    call DrawScore
    popa
    ret
DrawHud endp

; ---- 5-digit score under the BATMAN name ----
DrawScore proc near
    pusha
    mov ax,[score]
    mov bx,10
    mov di,4
scr_l:
    xor dx,dx
    div bx
    add dl,'0'
    mov [scorestr+di],dl
    dec di
    jns scr_l
    mov word ptr [txt_sc],1
    mov word ptr [txt_col],1
    mov word ptr [txt_x],31
    mov word ptr [txt_y],30
    mov si,offset scorestr
    call DrawStr
    popa
    ret
DrawScore endp
; ============================================================
;  BASIC ROUTINES
; ============================================================

; ---- wait for vertical retrace ----
WaitVsync proc near
    push ax
    push dx
    mov dx,3DAh
wv1:
    in al,dx
    test al,8
    jnz wv1
wv2:
    in al,dx
    test al,8
    jz wv2
    pop dx
    pop ax
    ret
WaitVsync endp

; ---- random number: AX = new random ----
Rand proc near
    push bx
    push dx
    mov ax,[seed]
    mov bx,25173
    mul bx
    add ax,13849
    mov [seed],ax
    pop dx
    pop bx
    ret
Rand endp

; ---- filled rectangle: AX=x BX=y CX=w DX=h SI=color ----
FillRect proc near
    pusha
    push es
    cld
    mov es,[drawseg]
    mov di,bx
    shl di,6
    shl bx,8
    add di,bx
    add di,ax                   ; di = y*320 + x
    mov ax,si                   ; al = color
    mov bx,cx                   ; bx = width
fr_row:
    mov cx,bx
    push di
    rep stosb
    pop di
    add di,320
    dec dx
    jnz fr_row
    pop es
    popa
    ret
FillRect endp

; ---- bevel border: AX=x BX=y CX=w DX=h SI=light DI=dark ----
Bevel proc near
    pusha
    mov [bv_x],ax
    mov [bv_y],bx
    mov [bv_w],cx
    mov [bv_h],dx
    mov [bv_l],si
    mov [bv_d],di
    mov ax,[bv_x]               ; top (light)
    mov bx,[bv_y]
    mov cx,[bv_w]
    mov dx,1
    mov si,[bv_l]
    call FillRect
    mov cx,1                    ; left (light)
    mov dx,[bv_h]
    call FillRect
    mov ax,[bv_x]               ; bottom (dark)
    mov bx,[bv_y]
    add bx,[bv_h]
    dec bx
    mov cx,[bv_w]
    mov dx,1
    mov si,[bv_d]
    call FillRect
    mov ax,[bv_x]               ; right (dark)
    add ax,[bv_w]
    dec ax
    mov bx,[bv_y]
    mov cx,1
    mov dx,[bv_h]
    call FillRect
    popa
    ret
Bevel endp

; ---- triangle apex up: AX=center x BX=top y CX=height DX=slope shift SI=color ----
TriUp proc near
    pusha
    mov [t_cx],ax
    mov [t_y],bx
    mov [t_h],cx
    mov [t_sh],dx
    mov [t_col],si
    mov word ptr [t_r],0
tu_l:
    mov dx,[t_r]
    mov cx,[t_sh]
    shr dx,cl                   ; half width = row >> shift
    mov ax,[t_cx]
    sub ax,dx
    mov cx,dx
    shl cx,1
    inc cx                      ; width = 2*half + 1
    mov bx,[t_y]
    add bx,[t_r]
    mov dx,1
    mov si,[t_col]
    call FillRect
    inc word ptr [t_r]
    mov ax,[t_r]
    cmp ax,[t_h]
    jb tu_l
    popa
    ret
TriUp endp

; ---- one character from the ROM font: AL = char ----
DrawChar proc near
    pusha
    push es
    xor ah,ah
    shl ax,3
    add ax,[font_off]
    mov si,ax
    mov bx,[font_seg]
    push ds
    pop es
    mov di,offset glyph
    mov ds,bx
    mov cx,8
    cld
    rep movsb                   ; copy 8 glyph bytes
    push es
    pop ds                      ; DS = data segment again
    mov word ptr [g_row],0
dc_row:
    mov bx,[g_row]
    mov al,[glyph+bx]
    mov [g_bits],al
    mov word ptr [g_col],0
dc_col:
    test byte ptr [g_bits],80h
    jz dc_skip
    mov ax,[g_col]
    mul word ptr [txt_sc]
    add ax,[txt_x]
    mov si,ax
    mov ax,[g_row]
    mul word ptr [txt_sc]
    add ax,[txt_y]
    mov bx,ax
    mov ax,si
    mov cx,[txt_sc]
    mov dx,cx
    mov si,[txt_col]
    call FillRect
dc_skip:
    shl byte ptr [g_bits],1
    inc word ptr [g_col]
    cmp word ptr [g_col],8
    jb dc_col
    inc word ptr [g_row]
    cmp word ptr [g_row],8
    jb dc_row
    mov ax,[txt_sc]
    shl ax,3
    add [txt_x],ax              ; move to next char position
    pop es
    popa
    ret
DrawChar endp

; ---- zero-terminated string at SI ----
DrawStr proc near
    push ax
    push si
str_l:
    mov al,[si]
    or al,al
    jz str_e
    call DrawChar
    inc si
    jmp str_l
str_e:
    pop si
    pop ax
    ret
DrawStr endp

; ============================================================
;  PALETTE + FADE
; ============================================================
InitPal proc near
    pusha
    push ds
    pop es
    cld
    mov si,offset palA
    mov di,offset palbuf
    mov cx,16*3
    rep movsb                   ; colors 0..15
    xor bx,bx                   ; colors 16..31 = red gradient (moon)
ip_g:
    mov ax,bx
    mov dl,38
    mul dl
    mov dl,15
    div dl
    add al,14
    stosb                       ; R : 14 .. 52
    mov al,bl
    shr al,2
    stosb                       ; G : 0 .. 3
    xor al,al
    stosb                       ; B : 0
    inc bx
    cmp bx,16
    jb ip_g
    mov si,offset palB
    mov cx,16*3
    rep movsb                   ; colors 32..47
    mov si,offset palC
    mov cx,16*3
    rep movsb                   ; colors 48..63 (Alfred)
    popa
    ret
InitPal endp

; AL = brightness 0..32 (32 = normal)
SetPal proc near
    pusha
    mov bl,al
    mov dx,3C8h
    xor al,al
    out dx,al
    inc dx
    mov si,offset palbuf
    mov cx,256*3
sp_l:
    mov al,[si]
    mul bl
    shr ax,5
    out dx,al
    inc si
    loop sp_l
    popa
    ret
SetPal endp

FadeOut proc near
    push ax
    push cx
    mov cx,32
fo_l:
    mov al,cl
    dec al
    call SetPal
    call WaitVsync
    loop fo_l
    pop cx
    pop ax
    ret
FadeOut endp

FadeIn proc near
    push ax
    push bx
    xor bl,bl
fi_l:
    inc bl
    mov al,bl
    call SetPal
    call WaitVsync
    cmp bl,32
    jb fi_l
    pop bx
    pop ax
    ret
FadeIn endp

; ============================================================
;  TITLE SCREEN
; ============================================================

; ---- red gradient moon: center (160,80) radius 60, colors 16..31 ----
FillCircleGrad proc near
    pusha
    mov word ptr [c_dy],-60
cg_row:
    mov ax,[c_dy]
    imul ax                     ; ax = dy*dy
    mov bx,3600
    sub bx,ax                   ; bx = r*r - dy*dy
    xor si,si                   ; si = half width (integer sqrt)
cg_sq:
    mov ax,si
    inc ax
    mul ax
    cmp ax,bx
    ja cg_sq_done
    inc si
    jmp cg_sq
cg_sq_done:
    mov ax,[c_dy]
    add ax,60
    shl ax,4
    xor dx,dx
    mov cx,121
    div cx
    add ax,16
    mov di,ax                   ; di = color of this row
    mov ax,160
    sub ax,si                   ; x
    mov bx,[c_dy]
    add bx,80                   ; y
    mov cx,si
    shl cx,1
    inc cx                      ; width
    mov dx,1
    push si
    mov si,di
    call FillRect
    pop si
    inc word ptr [c_dy]
    cmp word ptr [c_dy],60
    jle cg_row
    popa
    ret
FillCircleGrad endp

; ---- load a .BIN file: DX = file name, SI = 576-byte palette buffer,
;      AX = segment that receives the 64000 pixel bytes ----
LoadBin proc near
    pusha
    mov bp,ax                   ; keep the pixel segment
    mov ax,3D00h                ; open file
    int 21h
    jc lb_fail
    mov bx,ax                   ; file handle
    mov dx,si                   ; palette (colors 64..255)
    mov cx,576
    mov ah,3Fh
    int 21h
    push ds
    mov ds,bp                   ; 64000 pixel bytes
    xor dx,dx
    mov cx,64000
    mov ah,3Fh
    int 21h
    pop ds
    mov ah,3Eh                  ; close file
    int 21h
    popa
    ret
lb_fail:
    mov ax,3
    int 10h
    mov dx,offset msgfile
    mov ah,9
    int 21h
    mov ax,4C01h
    int 21h
LoadBin endp

; ---- "AMUSED TO DEATH" title card (any key skips) ----
ShowAmused proc near
    pusha
    mov dx,offset fname3        ; AMUSED.BIN: palette -> palbuf, pixels -> buffer
    mov si,offset palbuf+192
    mov ax,[bufseg]
    call LoadBin
    mov word ptr [drawseg],0A000h
    mov ax,[bufseg]
    call CopyBuf                ; screen is black (faded out) while we draw
    call FadeIn
    mov cx,210                  ; hold about 3 seconds
sa_w:
    call WaitVsync
    mov ah,1
    int 16h
    jz sa_n
    xor ah,ah                   ; a key was pressed: skip the card
    int 16h
    jmp sa_x
sa_n:
    loop sa_w
sa_x:
    call FadeOut
    popa
    ret
ShowAmused endp

; ---- Bruce colors (64..79) for the cutscene ----
UseBrucePal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset palE
    mov di,offset palbuf+192
    mov cx,24
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseBrucePal endp

; ---- Harley colors (80..95) for the cutscene ----
UseHarleyPal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset palF
    mov di,offset palbuf+240
    mov cx,24
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseHarleyPal endp



; ---- Joker portrait colors (96..111) ----
UseJokerPal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset palG
    mov di,offset palbuf+288
    mov cx,24
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseJokerPal endp

; ---- Joker TV colors (112..127) ----
UseJokerTvPal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset palH
    mov di,offset palbuf+336
    mov cx,24
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseJokerTvPal endp

; ---- Batman portrait colors (128..143) ----
UseBatmanPal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset palI
    mov di,offset palbuf+384
    mov cx,24
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseBatmanPal endp


; ---- Equipment screen colors (144..159) ----
UseEquipPal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset palJ
    mov di,offset palbuf+432
    mov cx,24
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseEquipPal endp


; ---- copy the saved palettes into the working palette ----
UseTitlePal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset titlepal
    mov di,offset palbuf+192
    mov cx,288
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseTitlePal endp

UseOptPal proc near
    push ax
    push cx
    push si
    push di
    push es
    push ds
    pop es
    cld
    mov si,offset optpal
    mov di,offset palbuf+192
    mov cx,288
    rep movsw
    pop es
    pop di
    pop si
    pop cx
    pop ax
    ret
UseOptPal endp

DrawTitle proc near
    pusha
    mov ax,[bufseg]
    mov [drawseg],ax
    mov dx,offset fname
    mov si,offset titlepal
    mov ax,[bufseg]
    call LoadBin                ; TITLE.BIN -> title buffer
    call UseTitlePal
    mov al,32
    call SetPal                 ; send the new palette to the screen
    popa
    ret
DrawTitle endp

; ---- slide the buffer from the bottom up to the center ----
SlideTitle proc near
    pusha
    push ds
    push es
    mov bx,[bufseg]
    mov ax,0A000h
    mov es,ax
    mov ds,bx                   ; DS = buffer (source)
    mov bp,200                  ; top row of the picture on screen
sl_f:
    REPT SLIDE_DELAY
    call WaitVsync
    ENDM
    mov ax,200
    sub ax,bp                   ; rows to copy
    mov cx,ax
    shl ax,7
    shl cx,5
    add cx,ax                   ; words = rows * 160
    mov di,bp
    shl di,6
    mov ax,bp
    shl ax,8
    add di,ax                   ; di = bp * 320
    xor si,si
    cld
    rep movsw
    sub bp,SLIDE_STEP
    jns sl_f
    pop es
    pop ds
    popa
    ret
SlideTitle endp

; ============================================================
;  TITLE MENU + OPTION MODE
; ============================================================
BlinkCol proc near
    push ax
    mov ax,[blink]
    and ax,32
    mov word ptr [txt_col],1
    jnz bc_x
    mov word ptr [txt_col],12
bc_x:
    pop ax
    ret
BlinkCol endp

DrawMenu proc near
    pusha
    mov word ptr [txt_sc],1
    mov word ptr [txt_col],3
    cmp byte ptr [menusel],0
    jne mn_a
    call BlinkCol
mn_a:
    mov word ptr [txt_x],120
    mov word ptr [txt_y],173
    mov si,offset sStart
    call DrawStr
    mov word ptr [txt_col],3
    cmp byte ptr [menusel],1
    jne mn_b
    call BlinkCol
mn_b:
    mov word ptr [txt_x],136
    mov word ptr [txt_y],186
    mov si,offset sOption
    call DrawStr
    mov word ptr [txt_col],0    ; marker 1 (black = erase)
    cmp byte ptr [menusel],0
    jne mn_c
    mov word ptr [txt_col],1
mn_c:
    mov word ptr [txt_x],104
    mov word ptr [txt_y],173
    mov al,'>'
    call DrawChar
    mov word ptr [txt_col],0    ; marker 2
    cmp byte ptr [menusel],1
    jne mn_d
    mov word ptr [txt_col],1
mn_d:
    mov word ptr [txt_x],120
    mov word ptr [txt_y],186
    mov al,'>'
    call DrawChar
    popa
    ret
DrawMenu endp

; ---- copy a 64000-byte buffer (segment in AX) to the screen ----
CopyBuf proc near
    push ax
    push cx
    push si
    push di
    push ds
    push es
    mov ds,ax
    mov ax,0A000h
    mov es,ax
    xor si,si
    xor di,di
    mov cx,32000
    cld
    rep movsw
    pop es
    pop ds
    pop di
    pop si
    pop cx
    pop ax
    ret
CopyBuf endp

RestoreTitle proc near
    push ax
    mov ax,[bufseg]
    call CopyBuf
    pop ax
    ret
RestoreTitle endp

; ---- draw value of option BL (0=level 1=music 2=sound) ----
DrawValue proc near
    push ax
    push bx
    push si
    cmp bl,0
    je dv_lvl
    cmp bl,1
    je dv_mus
    mov al,[opt_sound]
    xor ah,ah
    shl ax,1
    mov bx,ax
    mov si,[snd_tab+bx]
    jmp dv_draw
dv_lvl:
    mov al,[opt_level]
    xor ah,ah
    shl ax,1
    mov bx,ax
    mov si,[lvl_tab+bx]
    jmp dv_draw
dv_mus:
    mov al,[opt_music]
    xor ah,ah
    shl ax,1
    mov bx,ax
    mov si,[mus_tab+bx]
dv_draw:
    call DrawStr
    pop si
    pop bx
    pop ax
    ret
DrawValue endp

; ---- option screen (everything redrawn each time) ----
DrawOptionScreen proc near
    pusha
    mov word ptr [drawseg],0A000h
    mov ax,[bufseg2]
    call CopyBuf                ; option background picture
    mov word ptr [txt_sc],2
    mov word ptr [txt_col],13
    mov word ptr [txt_x],72
    mov word ptr [txt_y],6
    mov si,offset sOpTitle
    call DrawStr
    mov word ptr [txt_sc],1

    ; --- CONTROL list ---
    mov word ptr [txt_col],13
    mov word ptr [txt_x],40
    mov word ptr [txt_y],48
    mov si,offset sOpCtrl
    call DrawStr
    xor bx,bx
    mov di,60
op_ctl:
    push bx
    shl bx,2
    mov si,[ctl_tab+bx]         ; action name
    mov dx,[ctl_tab+bx+2]       ; key name
    pop bx
    mov word ptr [txt_col],3
    mov word ptr [txt_x],64
    mov [txt_y],di
    call DrawStr
    mov word ptr [txt_col],1
    mov word ptr [txt_x],150
    mov si,dx
    call DrawStr
    add di,10
    inc bx
    cmp bx,6
    jb op_ctl

    ; --- selectable rows: LEVEL, MUSIC, SOUND MODE ---
    xor bx,bx
op_row:
    mov di,bx
    shl di,1
    mov di,[row_y+di]
    mov word ptr [txt_col],13
    cmp bl,[optsel]
    jne op_ns
    mov word ptr [txt_col],1
    mov word ptr [txt_x],24
    mov [txt_y],di
    mov al,'>'
    call DrawChar
op_ns:
    mov word ptr [txt_x],40
    mov [txt_y],di
    push bx
    shl bx,1
    mov si,[oplab+bx]
    pop bx
    call DrawStr
    mov word ptr [txt_x],150
    call DrawValue
    inc bl
    cmp bl,3
    jb op_row

    ; --- START TO EXIT ---
    mov word ptr [txt_col],13
    cmp byte ptr [optsel],3
    jne op_ex
    mov word ptr [txt_col],1
    mov word ptr [txt_x],92
    mov word ptr [txt_y],160
    mov al,'>'
    call DrawChar
op_ex:
    mov word ptr [txt_x],108
    mov word ptr [txt_y],160
    mov si,offset sOpExit
    call DrawStr
    mov word ptr [txt_col],3    ; hint line
    mov word ptr [txt_x],28
    mov word ptr [txt_y],184
    mov si,offset sOpHint
    call DrawStr
    popa
    ret
DrawOptionScreen endp

; ---- toggle the selected option ----
ChangeOpt proc near
    push ax
    mov al,[optsel]
    cmp al,0
    je co_lvl
    cmp al,1
    je co_mus
    cmp al,2
    je co_snd
    jmp co_end
co_lvl:
    xor byte ptr [opt_level],1
    jmp co_end
co_mus:
    xor byte ptr [opt_music],1
    jmp co_end
co_snd:
    xor byte ptr [opt_sound],1
co_end:
    pop ax
    ret
ChangeOpt endp

; ---- the OPTION MODE screen loop ----
OptionMode proc near
    pusha
    call FadeOut
    call UseOptPal
    mov byte ptr [optsel],0
    call DrawOptionScreen
    call FadeIn
om_key:
    xor ah,ah
    int 16h
    cmp ah,1                    ; ESC
    je om_exit
    cmp ah,48h                  ; UP
    je om_up
    cmp ah,50h                  ; DOWN
    je om_down
    cmp ah,4Bh                  ; LEFT
    je om_change
    cmp ah,4Dh                  ; RIGHT
    je om_change
    cmp al,13
    je om_enter
    cmp al,' '
    je om_enter
    jmp om_key
om_up:
    cmp byte ptr [optsel],0
    je om_wrap
    dec byte ptr [optsel]
    jmp om_redraw
om_wrap:
    mov byte ptr [optsel],3
    jmp om_redraw
om_down:
    inc byte ptr [optsel]
    cmp byte ptr [optsel],4
    jb om_redraw
    mov byte ptr [optsel],0
    jmp om_redraw
om_enter:
    cmp byte ptr [optsel],3
    je om_exit
om_change:
    call ChangeOpt
om_redraw:
    call WaitVsync
    call DrawOptionScreen
    jmp om_key
om_exit:
    call FadeOut
    call UseTitlePal
    call RestoreTitle
    call FadeIn
    popa
    ret
OptionMode endp

; ============================================================
;  CUTSCENE : CONSOLE, MONITOR, PORTRAIT, TEXT
; ============================================================

; ---- Batcave console (background + frames) ----
DrawConsole proc near
    pusha
    RECTF 0,0,320,44,44         ; gradient background (3 bands)
    RECTF 0,44,320,50,4
    RECTF 0,94,320,40,5
    mov word ptr [lp],45        ; dither seams between bands
dcn_dz:
    RECTF [lp],44,2,1,44
    add word ptr [lp],4
    cmp word ptr [lp],320
    jb dcn_dz
    mov word ptr [lp],1
dcn_dz2:
    RECTF [lp],94,2,1,4
    add word ptr [lp],4
    cmp word ptr [lp],320
    jb dcn_dz2

    LAMP 20,8,9                 ; top lights
    LAMP 40,8,10
    LAMP 60,8,9
    LAMP 305,34,10              ; right lights
    LAMP 305,50,9
    LAMP 305,66,9
    LAMP 305,82,10

    RECTF 0,28,78,84,7          ; left vent panel
    BEVEL 0,28,78,84,46,45
    RECTF 1,29,76,1,8
    RIVET 4,31
    RIVET 71,31
    RIVET 4,104
    RIVET 71,104
    mov word ptr [lp],40
dcn_vent:
    RECTF 10,[lp],58,5,45       ; slot shadow
    RECTF 10,[lp],58,3,12
    RECTF 10,[lp],58,1,11       ; slot top lip
    add word ptr [lp],9
    cmp word ptr [lp],112
    jb dcn_vent

    RECTF 88,14,144,112,45      ; monitor drop shadow
    RECTF 90,16,140,108,7       ; monitor frame
    BEVEL 90,16,140,108,46,45
    RECTF 93,19,134,102,8
    BEVEL 93,19,134,102,46,7
    RIVET 93,19
    RIVET 224,19
    RIVET 93,118
    RIVET 224,118
    RECTF 97,25,126,90,45       ; screen inner bezel (sunken)
    RECTF 98,26,124,88,0        ; monitor screen
    RECTF 97,25,126,1,12
    RECTF 97,25,1,90,12

    RECTF 246,24,50,96,11       ; speaker
    BEVEL 246,24,50,96,3,12
    RECTF 252,30,38,40,12
    BEVEL 252,30,38,40,0,11
    mov word ptr [lp],32
dcn_spk:
    RECTF 254,[lp],34,2,11
    add word ptr [lp],4
    cmp word ptr [lp],68
    jb dcn_spk
    mov word ptr [lp],33        ; second pass: perforation dots
dcn_spk2:
    RECTF 256,[lp],30,1,3
    add word ptr [lp],4
    cmp word ptr [lp],68
    jb dcn_spk2
    RECTF 262,80,18,18,12
    BEVEL 262,80,18,18,0,11
    RECTF 264,84,14,1,11
    RECTF 264,88,14,1,11
    RECTF 264,92,14,1,11
    RECTF 264,104,3,3,38
    RECTF 275,104,3,3,38
    RECTF 265,104,1,1,47
    RECTF 276,104,1,1,47
    RIVET 249,27
    RIVET 290,27
    RIVET 249,113
    RIVET 290,113

    RECTF 0,134,320,2,6         ; separator lines
    RECTF 0,134,320,1,47
    RECTF 0,138,320,2,5
    RECTF 6,142,78,58,11        ; portrait frame
    BEVEL 6,142,78,58,3,12
    RECTF 8,144,74,55,0
    BEVEL 8,144,74,55,12,11
    RECTF 84,146,230,52,6       ; text box
    BEVEL 84,146,230,52,47,5
    RECTF 86,148,226,48,0
    BEVEL 86,148,226,48,12,6
    RECTF 0,142,4,58,11         ; side panels
    BEVEL 0,142,4,58,3,12
    RECTF 316,142,4,58,11
    BEVEL 316,142,4,58,3,12
    RIVET 96,139
    RIVET 220,139
    popa
    ret
DrawConsole endp

; ---- monitor content: AL = M_xxx ----
DrawMonitor proc near
    pusha
    cmp al,M_BLACK
    je dm_black
    cmp al,M_HARLEY
    je dm_harley
    cmp al,M_JOKER
    je dm_joker
    cmp al,M_PARK
    je dm_park
    cmp al,M_PARKH
    je dm_parkh
    cmp al,M_EQUIP
    je dm_equip
    call DrawStatic
    jmp dm_end
dm_black:
    RECTF 98,26,124,88,0
    jmp dm_end
dm_harley:
    RECTF 98,26,124,88,0
    call DrawHarley
    jmp dm_end
dm_joker:
    call DrawJoker
    jmp dm_end
dm_park:
    call DrawPark
    jmp dm_end
dm_parkh:
    call DrawPark
    call DrawHarleySmall        ; was: call DrawHarley
    jmp dm_end
dm_equip:
    call DrawEquip
    jmp dm_end
dm_end:
    popa
    ret
DrawMonitor endp

; ---- Harley on the monitor (right side) ----
; ---- Harley on the monitor, big (scaled 5/3 -> 123x70) ----
DrawHarley proc near
    pusha
    push es
    RECTF 98,26,124,88,0        ; clear the screen black first
    mov ax,0A000h
    mov es,ax
    cld
    xor bx,bx                   ; bx = dest row 0..69
dh_row:
    mov ax,bx
    mov cx,3
    mul cx
    mov cx,5
    xor dx,dx
    div cx                      ; ax = source row = row*3/5
    mov cx,74
    mul cx
    add ax,offset harley_img
    mov si,ax                   ; si = start of source row
    mov ax,bx
    add ax,35                   ; screen y (centered in monitor)
    mov di,ax
    shl di,6
    shl ax,8
    add di,ax
    add di,98                   ; di = y*320 + 98
    xor bp,bp                   ; bp = dest col 0..122
dh_col:
    mov ax,bp
    mov cx,3
    mul cx
    mov cx,5
    xor dx,dx
    div cx                      ; ax = source col
    push si
    add si,ax
    mov al,[si]
    pop si
    stosb
    inc bp
    cmp bp,123
    jb dh_col
    inc bx
    cmp bx,70
    jb dh_row
    pop es
    popa
    ret
DrawHarley endp

; ---- Harley on the monitor, small corner copy (for the park scene) ----
DrawHarleySmall proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset harley_img
    mov di,72*320+146
    mov dx,42
    cld
dhs_row:
    mov cx,74
    rep movsb
    add di,320-74
    dec dx
    jnz dhs_row
    pop es
    popa
    ret
DrawHarleySmall endp
; ---- Joker under the spotlight ----
; ---- Joker under the spotlight (bitmap 124x88 -> monitor at 98,26) ----
DrawJoker proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset jokertv_img
    mov di,26*320+98
    mov dx,88
    cld
dj_row:
    mov cx,124
    rep movsb
    add di,320-124
    dec dx
    jnz dj_row
    pop es
    popa
    ret
DrawJoker endp

; ---- Equipment screen (bitmap 124x88 -> monitor at 98,26) ----
DrawEquip proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset equip_img
    mov di,26*320+98
    mov dx,88
    cld
de_row:
    mov cx,124
    rep movsb
    add di,320-124
    dec dx
    jnz de_row
    pop es
    popa
    ret
DrawEquip endp

; ---- amusement park silhouette ----
DrawPark proc near
    pusha
    RECTF 98,26,124,22,34       ; red sky bands
    RECTF 98,48,124,22,35
    RECTF 98,70,124,22,36
    RECTF 98,92,124,22,37
    TRIANG 150,54,34,1,0        ; circus tent
    RECTF 128,86,44,22,0
    RECTF 178,64,2,30,0         ; carousel
    TRIANG 179,56,10,0,0
    RECTF 168,88,24,12,0
    TRIANG 112,58,40,2,0        ; roller coaster
    RECTF 100,94,40,2,0
    TRIANG 205,66,32,2,0
    RECTF 190,32,9,9,38         ; moon glow
    RECTF 191,31,7,11,38
    RECTF 192,33,5,7,3
    RECTF 98,100,124,14,0       ; ground
    RECTF 98,98,124,2,38        ; fence rail
    mov word ptr [lp],100
dp_fence:
    RECTF [lp],92,2,18,38
    add word ptr [lp],6
    cmp word ptr [lp],220
    jb dp_fence
    popa
    ret
DrawPark endp

; ---- TV static noise inside the monitor ----
DrawStatic proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    cld
    mov di,26*320+98
    mov dx,88
st_row:
    mov cx,62
st_px:
    call Rand
    mov si,ax
    mov bx,si
    shr bx,6
    and bx,3
    mov al,[noise_tab+bx]
    stosb
    mov bx,si
    shr bx,12
    and bx,3
    mov al,[noise_tab+bx]
    stosb
    loop st_px
    add di,320-124
    dec dx
    jnz st_row
    pop es
    popa
    ret
DrawStatic endp

; ---- portrait + name label: AL = S_xxx (0 = empty box) ----
DrawPortrait proc near
    pusha
    or al,al
    jnz dp_some
    RECTF 8,144,74,55,0
    jmp dp_x
dp_some:
    mov [spk],al
    cmp al,S_ALFRED
    je dp_alfred
    cmp al,S_BRUCE
    je dp_bruce
    cmp al,S_HARLEY
    je dp_harley
    cmp al,S_JOKER
    je dp_joker
    jmp dp_batman

dp_alfred:
    call DrawAlfredImg          ; Alfred sprite (ALFRED.INC)
    jmp dp_label
dp_bruce:
    call DrawBruceImg           ; Bruce sprite (BRUCE.INC)
    jmp dp_label
dp_harley:
    call DrawHarleyImg          ; Harley sprite (HARLEY.INC)
    jmp dp_label
dp_joker:
    call DrawJokerImg           ; Joker sprite (JOKER.INC)
    jmp dp_label
dp_batman:
    call DrawBatmanImg          ; Batman sprite (BATPORT.INC)
    jmp dp_label

dp_label:
    RECTF 8,186,74,12,1         ; white name strip
    mov al,[spk]
    dec al
    xor ah,ah
    shl ax,2
    mov bx,ax
    mov si,[spk_tab+bx]
    mov ax,[spk_tab+bx+2]
    mov [txt_x],ax
    mov word ptr [txt_y],188
    mov word ptr [txt_sc],1
    mov word ptr [txt_col],0
    call DrawStr
dp_x:
    popa
    ret
DrawPortrait endp

; ---- Alfred bitmap 74x42 -> portrait box at (8,144) ----
DrawAlfredImg proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset alf_img
    mov di,144*320+8
    mov dx,42
    cld
dai_row:
    mov cx,74
    rep movsb
    add di,320-74
    dec dx
    jnz dai_row
    pop es
    popa
    ret
DrawAlfredImg endp

; ---- Bruce bitmap 74x42 -> portrait box at (8,144) ----
DrawBruceImg proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset bruce_img
    mov di,144*320+8
    mov dx,42
    cld
dbi_row:
    mov cx,74
    rep movsb
    add di,320-74
    dec dx
    jnz dbi_row
    pop es
    popa
    ret
DrawBruceImg endp

; ---- Harley bitmap 74x42 -> portrait box at (8,144) ----
DrawHarleyImg proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset harley_img
    mov di,144*320+8
    mov dx,42
    cld
dhi_row:
    mov cx,74
    rep movsb
    add di,320-74
    dec dx
    jnz dhi_row
    pop es
    popa
    ret
DrawHarleyImg endp

; ---- Joker bitmap 74x42 -> portrait box at (8,144) ----
DrawJokerImg proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset joker_img
    mov di,144*320+8
    mov dx,42
    cld
dji_row:
    mov cx,74
    rep movsb
    add di,320-74
    dec dx
    jnz dji_row
    pop es
    popa
    ret
DrawJokerImg endp



; ---- Batman bitmap 74x42 -> portrait box at (8,144) ----
DrawBatmanImg proc near
    pusha
    push es
    mov ax,0A000h
    mov es,ax
    mov si,offset batman_img
    mov di,144*320+8
    mov dx,42
    cld
dbm_row:
    mov cx,74
    rep movsb
    add di,320-74
    dec dx
    jnz dbm_row
    pop es
    popa
    ret
DrawBatmanImg endp

; ---- typewriter text: BX = line 1, DX = line 2 ----
TypeLines proc near
    pusha
    mov byte ptr [fastf],0
    mov word ptr [txt_sc],1
    mov word ptr [txt_col],13
    mov word ptr [txt_x],94
    mov word ptr [txt_y],158
    mov si,bx
    call TypeOne
    mov word ptr [txt_x],94
    mov word ptr [txt_y],174
    mov si,dx
    call TypeOne
    popa
    ret
TypeLines endp

; SI = string
TypeOne proc near
to_l:
    mov al,[si]
    or al,al
    jz to_e
    call DrawChar
    inc si
    cmp byte ptr [fastf],0
    jne to_l
    call WaitVsync
    call WaitVsync
    mov ah,1
    int 16h
    jz to_l
    xor ah,ah                   ; a key was pressed: take it
    int 16h
    cmp ah,1
    jne to_f
    mov byte ptr [skipf],1
to_f:
    mov byte ptr [fastf],1      ; show the rest instantly
    jmp to_l
to_e:
    ret
TypeOne endp

; ---- timed page: CX = frames (animates the static) ----
AutoWait proc near
    push ax
aw_l:
    cmp byte ptr [curmon],M_STATIC
    jne aw_ns
    call DrawStatic
aw_ns:
    call WaitVsync
    mov ah,1
    int 16h
    jz aw_nk
    xor ah,ah
    int 16h
    cmp ah,1
    jne aw_nk
    mov byte ptr [skipf],1
    jmp aw_x
aw_nk:
    loop aw_l
aw_x:
    pop ax
    ret
AutoWait endp

END start
