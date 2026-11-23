; Alfred portrait converted from the supplied 102x110 image.
; VGA Mode 13h: 8-bit indexed pixels, 256-color palette.
; This image is opaque; the original background and frame are included.

ALFRED_WIDTH  EQU 102
ALFRED_HEIGHT EQU 110
ALFRED_SIZE   EQU 11220

; Palette format: RGB triplets scaled to VGA DAC range 0..63.
ALFRED_PALETTE LABEL BYTE
    db 2Fh,2Fh,2Fh ; color 0
    db 2Fh,2Eh,2Eh ; color 1
    db 2Eh,2Eh,2Eh ; color 2
    db 2Dh,2Dh,2Dh ; color 3
    db 2Dh,2Dh,2Dh ; color 4
    db 2Fh,2Dh,2Bh ; color 5
    db 2Dh,2Dh,2Dh ; color 6
    db 2Dh,2Ch,2Ch ; color 7
    db 2Dh,2Ch,2Ah ; color 8
    db 2Bh,2Ah,28h ; color 9
    db 2Bh,2Bh,2Bh ; color 10
    db 2Bh,2Ah,29h ; color 11
    db 2Ah,2Ah,2Ah ; color 12
    db 2Ah,2Ah,2Ah ; color 13
    db 2Bh,2Ah,28h ; color 14
    db 2Ah,2Ah,2Ah ; color 15
    db 2Bh,2Ah,27h ; color 16
    db 2Ah,29h,27h ; color 17
    db 2Ah,29h,26h ; color 18
    db 29h,29h,29h ; color 19
    db 28h,28h,27h ; color 20
    db 27h,28h,27h ; color 21
    db 27h,28h,27h ; color 22
    db 28h,27h,26h ; color 23
    db 27h,27h,27h ; color 24
    db 26h,27h,26h ; color 25
    db 26h,26h,25h ; color 26
    db 25h,25h,24h ; color 27
    db 25h,25h,25h ; color 28
    db 25h,25h,24h ; color 29
    db 24h,23h,22h ; color 30
    db 22h,22h,22h ; color 31
    db 27h,21h,1Bh ; color 32
    db 25h,20h,17h ; color 33
    db 23h,21h,1Eh ; color 34
    db 23h,1Eh,1Ah ; color 35
    db 21h,21h,1Fh ; color 36
    db 20h,20h,1Fh ; color 37
    db 1Fh,1Fh,1Fh ; color 38
    db 20h,1Eh,1Dh ; color 39
    db 21h,1Dh,15h ; color 40
    db 1Eh,1Dh,1Dh ; color 41
    db 20h,1Ch,17h ; color 42
    db 22h,1Ch,11h ; color 43
    db 1Fh,1Ah,13h ; color 44
    db 1Dh,1Ch,1Bh ; color 45
    db 1Ch,1Ch,1Ch ; color 46
    db 1Bh,1Bh,1Ah ; color 47
    db 19h,1Ah,1Bh ; color 48
    db 27h,1Ah,16h ; color 49
    db 27h,1Ah,16h ; color 50
    db 21h,1Ah,0Eh ; color 51
    db 1Ah,1Ah,19h ; color 52
    db 27h,1Ah,16h ; color 53
    db 26h,1Ah,16h ; color 54
    db 26h,1Ah,16h ; color 55
    db 26h,19h,16h ; color 56
    db 26h,19h,16h ; color 57
    db 26h,19h,15h ; color 58
    db 26h,19h,15h ; color 59
    db 25h,19h,15h ; color 60
    db 26h,19h,15h ; color 61
    db 25h,18h,14h ; color 62
    db 25h,18h,15h ; color 63
    db 25h,18h,13h ; color 64
    db 24h,18h,15h ; color 65
    db 23h,17h,14h ; color 66
    db 21h,1Ah,11h ; color 67
    db 20h,19h,0Eh ; color 68
    db 20h,19h,0Eh ; color 69
    db 20h,19h,0Eh ; color 70
    db 22h,17h,14h ; color 71
    db 1Fh,19h,0Dh ; color 72
    db 1Fh,18h,0Ch ; color 73
    db 1Fh,18h,0Dh ; color 74
    db 1Fh,18h,0Ch ; color 75
    db 1Eh,18h,0Ch ; color 76
    db 1Eh,18h,0Ch ; color 77
    db 1Ch,18h,11h ; color 78
    db 1Eh,17h,0Ch ; color 79
    db 1Eh,17h,0Ch ; color 80
    db 19h,19h,18h ; color 81
    db 19h,18h,17h ; color 82
    db 25h,17h,13h ; color 83
    db 24h,17h,13h ; color 84
    db 24h,16h,12h ; color 85
    db 24h,16h,12h ; color 86
    db 24h,16h,12h ; color 87
    db 23h,16h,11h ; color 88
    db 22h,16h,13h ; color 89
    db 21h,15h,12h ; color 90
    db 1Eh,17h,0Dh ; color 91
    db 1Eh,17h,0Bh ; color 92
    db 23h,15h,10h ; color 93
    db 23h,15h,10h ; color 94
    db 22h,14h,0Fh ; color 95
    db 20h,15h,11h ; color 96
    db 1Eh,14h,11h ; color 97
    db 21h,13h,0Dh ; color 98
    db 21h,12h,0Ch ; color 99
    db 1Fh,13h,0Eh ; color 100
    db 21h,12h,0Ch ; color 101
    db 1Dh,16h,0Dh ; color 102
    db 1Dh,16h,0Ah ; color 103
    db 1Ch,16h,0Ah ; color 104
    db 1Ch,16h,0Bh ; color 105
    db 1Ch,16h,0Ah ; color 106
    db 1Ch,15h,0Ah ; color 107
    db 1Ch,15h,0Ah ; color 108
    db 1Bh,15h,0Ah ; color 109
    db 1Bh,15h,0Ah ; color 110
    db 1Ah,15h,0Ah ; color 111
    db 1Dh,14h,11h ; color 112
    db 1Dh,13h,10h ; color 113
    db 1Ah,14h,0Ah ; color 114
    db 1Ah,14h,09h ; color 115
    db 1Ah,13h,0Bh ; color 116
    db 19h,13h,0Bh ; color 117
    db 19h,13h,09h ; color 118
    db 1Ch,13h,10h ; color 119
    db 19h,13h,08h ; color 120
    db 19h,12h,08h ; color 121
    db 19h,12h,08h ; color 122
    db 18h,12h,08h ; color 123
    db 20h,12h,0Ch ; color 124
    db 20h,12h,0Ch ; color 125
    db 20h,12h,0Ch ; color 126
    db 1Fh,11h,0Ch ; color 127
    db 1Eh,11h,0Bh ; color 128
    db 1Eh,10h,0Bh ; color 129
    db 1Dh,10h,0Bh ; color 130
    db 1Dh,10h,0Ah ; color 131
    db 1Ch,12h,0Fh ; color 132
    db 1Ch,10h,0Ch ; color 133
    db 1Ah,11h,0Eh ; color 134
    db 19h,11h,0Fh ; color 135
    db 17h,16h,16h ; color 136
    db 17h,16h,15h ; color 137
    db 16h,16h,16h ; color 138
    db 16h,15h,14h ; color 139
    db 14h,14h,14h ; color 140
    db 13h,13h,13h ; color 141
    db 18h,12h,09h ; color 142
    db 17h,11h,08h ; color 143
    db 15h,11h,0Dh ; color 144
    db 12h,11h,11h ; color 145
    db 14h,10h,0Bh ; color 146
    db 0Eh,10h,12h ; color 147
    db 12h,10h,0Dh ; color 148
    db 0Eh,10h,12h ; color 149
    db 1Ch,0Fh,0Ah ; color 150
    db 1Bh,0Eh,0Ah ; color 151
    db 1Ah,0Fh,0Bh ; color 152
    db 1Ah,0Eh,0Ah ; color 153
    db 19h,0Eh,09h ; color 154
    db 19h,0Eh,09h ; color 155
    db 1Ah,0Dh,09h ; color 156
    db 17h,0Fh,0Ch ; color 157
    db 18h,0Eh,09h ; color 158
    db 18h,0Dh,09h ; color 159
    db 14h,0Fh,0Dh ; color 160
    db 15h,0Fh,07h ; color 161
    db 14h,0Eh,09h ; color 162
    db 13h,0Eh,09h ; color 163
    db 15h,0Dh,0Ah ; color 164
    db 15h,0Dh,0Ah ; color 165
    db 15h,0Dh,0Ah ; color 166
    db 16h,0Dh,08h ; color 167
    db 14h,0Dh,07h ; color 168
    db 13h,0Dh,07h ; color 169
    db 19h,0Ch,08h ; color 170
    db 18h,0Ch,08h ; color 171
    db 18h,0Ch,08h ; color 172
    db 18h,0Ch,08h ; color 173
    db 17h,0Ch,08h ; color 174
    db 17h,0Bh,08h ; color 175
    db 16h,0Ch,08h ; color 176
    db 16h,0Ch,08h ; color 177
    db 16h,0Bh,07h ; color 178
    db 15h,0Ch,08h ; color 179
    db 14h,0Ch,09h ; color 180
    db 15h,0Bh,07h ; color 181
    db 14h,0Ah,07h ; color 182
    db 13h,0Ch,06h ; color 183
    db 13h,0Ch,06h ; color 184
    db 12h,0Bh,07h ; color 185
    db 13h,0Ah,07h ; color 186
    db 12h,09h,06h ; color 187
    db 13h,09h,06h ; color 188
    db 11h,0Eh,0Ch ; color 189
    db 0Fh,0Eh,0Dh ; color 190
    db 0Dh,0Dh,0Dh ; color 191
    db 0Ch,0Eh,10h ; color 192
    db 0Ch,0Eh,10h ; color 193
    db 0Ch,0Eh,10h ; color 194
    db 0Ch,0Dh,0Fh ; color 195
    db 11h,0Bh,06h ; color 196
    db 11h,0Ah,06h ; color 197
    db 10h,0Ch,07h ; color 198
    db 0Dh,0Ch,0Bh ; color 199
    db 10h,0Ah,06h ; color 200
    db 10h,09h,07h ; color 201
    db 11h,09h,06h ; color 202
    db 0Eh,09h,05h ; color 203
    db 11h,09h,06h ; color 204
    db 10h,08h,06h ; color 205
    db 0Fh,08h,06h ; color 206
    db 0Fh,08h,05h ; color 207
    db 0Fh,08h,05h ; color 208
    db 0Fh,08h,05h ; color 209
    db 0Eh,08h,05h ; color 210
    db 0Eh,07h,05h ; color 211
    db 0Ch,0Dh,10h ; color 212
    db 0Bh,0Dh,0Fh ; color 213
    db 0Ah,0Ch,0Fh ; color 214
    db 0Ah,0Ch,0Eh ; color 215
    db 0Bh,0Bh,0Bh ; color 216
    db 0Ah,0Bh,0Eh ; color 217
    db 0Bh,0Bh,0Bh ; color 218
    db 0Bh,0Ah,0Ah ; color 219
    db 0Bh,0Ah,0Bh ; color 220
    db 0Ah,0Ah,0Ah ; color 221
    db 09h,0Bh,0Dh ; color 222
    db 08h,0Ah,0Ch ; color 223
    db 08h,0Ah,0Ch ; color 224
    db 08h,08h,09h ; color 225
    db 0Ah,07h,04h ; color 226
    db 07h,07h,07h ; color 227
    db 08h,07h,06h ; color 228
    db 06h,07h,09h ; color 229
    db 0Dh,07h,04h ; color 230
    db 0Dh,07h,04h ; color 231
    db 0Dh,07h,04h ; color 232
    db 0Dh,06h,04h ; color 233
    db 0Dh,06h,04h ; color 234
    db 0Dh,06h,04h ; color 235
    db 0Dh,06h,04h ; color 236
    db 0Ch,06h,04h ; color 237
    db 0Ch,06h,04h ; color 238
    db 0Bh,06h,04h ; color 239
    db 08h,06h,04h ; color 240
    db 07h,05h,02h ; color 241
    db 0Ah,05h,03h ; color 242
    db 08h,04h,03h ; color 243
    db 05h,06h,08h ; color 244
    db 05h,05h,05h ; color 245
    db 06h,04h,03h ; color 246
    db 04h,03h,03h ; color 247
    db 04h,02h,02h ; color 248
    db 02h,01h,01h ; color 249
    db 01h,01h,01h ; color 250
    db 01h,01h,00h ; color 251
    db 01h,01h,01h ; color 252
    db 01h,00h,00h ; color 253
    db 00h,00h,00h ; color 254
    db 00h,00h,00h ; color 255

; Pixel indices, row-major: 102 bytes per row.
ALFRED_PIXELS LABEL BYTE
    db C0h,93h,93h,D6h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h

    db C0h,93h,93h,D6h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h,D9h
    db D9h,D9h,D9h,D9h,D9h,D9h

    db C0h,93h,93h,DEh,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h,E0h
    db E0h,E0h,E0h,E0h,E0h,E0h

    db C0h,93h,93h,C1h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h,C3h
    db C3h,C3h,C3h,C3h,C3h,C3h

    db C0h,93h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db C0h,93h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db C0h,93h,93h,0Fh,00h,20h,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh,2Bh
    db 2Bh,2Bh,2Bh,2Bh,0Bh,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,74h,C5h,C5h,C5h,C5h,C5h
    db C5h,C5h,C5h,C5h,C5h,C5h,C5h,C5h,C5h,C5h,C5h,C5h
    db C5h,C5h,A8h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,8Eh,EEh,EEh,EEh,EEh,EEh
    db EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh
    db EEh,EEh,CEh,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,8Eh,A8h,A8h,A8h,A7h,9Bh,9Bh,9Bh,9Bh,99h
    db 71h,71h,71h,71h,71h,71h,71h,71h,71h,71h,71h,71h
    db 84h,9Bh,9Eh,A8h,A8h,A8h,A8h,A8h,5Bh,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,A8h,EEh,EEh,EEh,B5h,65h,65h,65h,65h,62h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 40h,65h,82h,EEh,EEh,EEh,EEh,EEh,69h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,8Eh
    db A1h,A1h,B5h,BCh,B5h,AEh,97h,65h,65h,62h,56h,55h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 3Bh,56h,5Dh,86h,86h,AEh,AEh,AEh,A1h,A1h,66h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,CEh
    db EEh,EEh,B6h,ABh,96h,65h,65h,65h,65h,5Fh,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,36h,63h,65h,65h,CCh,EEh,75h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,CEh
    db EEh,EEh,B6h,ABh,96h,65h,65h,65h,65h,5Fh,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,36h,63h,65h,65h,CCh,EEh,75h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,74h,75h,B5h
    db BAh,BAh,AAh,97h,81h,65h,62h,5Eh,5Eh,58h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,36h,5Eh,5Eh,5Eh,9Dh,A6h,75h,74h
    db 74h,74h,74h,66h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,45h,E8h,EEh,82h
    db 65h,65h,65h,65h,65h,65h,5Dh,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db DDh,DDh,DDh,BDh,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,45h,69h,69h,D0h,D0h,81h
    db 65h,65h,65h,65h,62h,5Fh,56h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db BFh,BEh,BEh,90h,66h,66h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,5Bh,EEh,ECh,ADh,ABh,7Eh
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db 89h,22h,22h,51h,DDh,BDh,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,45h,4Ah,4Ah,69h,EFh,EFh,B2h,B2h,7Fh
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,36h
    db 42h,42h,42h,42h,42h,39h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db 88h,22h,22h,34h,C7h,BDh,4Ah,4Ah,4Ah,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FFh,FFh,FFh,96h
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,42h
    db FFh,FFh,FFh,FFh,FFh,77h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db 51h,18h,18h,1Bh,22h,2Dh,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FFh,FFh,FFh,96h
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,42h
    db FFh,FFh,FFh,FFh,FFh,77h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db 51h,18h,18h,1Bh,22h,2Dh,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FFh,FFh,FFh,F9h
    db F9h,F9h,86h,3Ah,37h,31h,31h,31h,31h,61h,F8h,F8h
    db FFh,FFh,FFh,FFh,FFh,F9h,F8h,87h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,94h,C7h,2Eh,1Dh
    db 1Ah,18h,18h,19h,19h,25h,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,87h,31h,31h,31h,31h,31h,31h,61h,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,9Dh,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,BDh,DDh,29h,18h
    db 18h,18h,18h,18h,18h,24h,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,D3h,9Ah,9Ah,9Ah,9Ah,9Ah
    db 9Ah,9Ah,5Ah,31h,31h,31h,31h,31h,31h,3Fh,61h,61h
    db 61h,61h,61h,61h,61h,F0h,FFh,9Dh,31h,31h,31h,31h
    db 31h,31h,42h,BDh,BDh,BDh,BDh,BDh,2Dh,24h,1Ch,18h
    db 18h,18h,18h,18h,18h,1Dh,2Dh,2Dh,2Dh,BDh,BDh,4Ah
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,CFh,65h,65h,65h,65h,65h
    db 65h,65h,53h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,E2h,FFh,9Dh,31h,31h,31h,31h
    db 31h,31h,47h,DDh,DDh,DDh,DDh,DDh,24h,18h,18h,18h
    db 18h,18h,18h,18h,18h,1Ah,22h,22h,22h,DAh,DDh,5Bh
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,CFh,65h,7Ch,BAh,BAh,80h
    db 65h,65h,53h,31h,31h,31h,31h,31h,31h,31h,31h,3Fh
    db A6h,A6h,3Fh,31h,31h,70h,87h,59h,31h,31h,31h,31h
    db 31h,31h,47h,DDh,DCh,2Eh,29h,29h,1Ch,18h,18h,18h
    db 18h,18h,18h,18h,18h,1Ah,22h,22h,22h,DAh,DDh,5Bh
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,CFh,65h,7Dh,EAh,EEh,82h
    db 65h,65h,53h,31h,31h,31h,31h,31h,31h,31h,31h,41h
    db EEh,EEh,41h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,47h,DDh,DAh,1Ah,18h,18h,18h,18h,18h,18h
    db 18h,18h,18h,18h,18h,1Ah,22h,22h,22h,DAh,DDh,5Bh
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,D3h,B1h,B1h,AEh,AEh,B1h
    db B1h,B1h,60h,31h,31h,31h,31h,31h,31h,41h,9Dh,9Dh
    db 86h,86h,3Ch,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,47h,DDh,DAh,1Eh,1Eh,1Eh,1Ah,18h,18h,18h
    db 18h,18h,18h,18h,18h,1Eh,8Bh,8Bh,8Bh,90h,90h,48h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,EEh,EEh,EAh,7Dh,65h,CFh
    db EEh,EEh,71h,31h,31h,31h,31h,31h,31h,5Ah,EEh,D1h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,47h,DDh,DAh,22h,22h,22h,1Ah,18h,18h,18h
    db 18h,18h,18h,18h,18h,24h,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,EEh,EEh,EAh,7Dh,65h,CFh
    db EEh,EEh,71h,31h,31h,31h,31h,31h,31h,5Ah,EEh,D1h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,41h,90h,90h,52h,52h,52h,1Eh,18h,18h,18h
    db 18h,18h,18h,1Ah,1Dh,26h,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,EEh,EEh,EAh,7Dh,65h,CFh
    db EEh,EEh,71h,31h,31h,31h,31h,31h,31h,5Ah,EEh,D1h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,39h,DBh,DDh,DDh,24h,18h,18h,18h
    db 18h,18h,18h,1Bh,22h,2Dh,DDh,DDh,DBh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,EEh,F3h,F2h,AEh,9Fh,D3h
    db EEh,EEh,71h,31h,31h,31h,47h,77h,77h,9Dh,F3h,EFh
    db 77h,77h,77h,77h,77h,5Ah,59h,54h,40h,3Dh,31h,31h
    db 31h,31h,31h,31h,39h,DBh,DDh,DDh,25h,1Bh,24h,27h
    db 27h,27h,27h,2Dh,34h,88h,BDh,BDh,BDh,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FFh,FFh,FFh,F2h
    db EEh,EEh,71h,31h,31h,31h,9Dh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,CAh,ABh,83h,65h,58h,31h,31h
    db 31h,31h,31h,31h,39h,DBh,DDh,DDh,2Dh,22h,A0h,EEh
    db EEh,EEh,EEh,EEh,EEh,C5h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FFh,FBh,FBh,E6h
    db CFh,CFh,61h,31h,31h,31h,87h,F6h,F6h,F7h,FFh,FDh
    db E4h,E4h,FDh,FFh,FFh,B4h,84h,85h,96h,60h,31h,31h
    db 31h,31h,31h,31h,39h,DBh,DDh,DDh,52h,2Dh,A0h,C9h
    db C9h,C9h,C9h,D1h,EEh,C5h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FFh,FEh,EEh,EEh,82h
    db 65h,65h,53h,31h,31h,31h,31h,31h,31h,61h,FFh,F7h
    db 05h,05h,F7h,FFh,FFh,24h,05h,91h,FFh,B4h,31h,31h
    db 31h,31h,31h,31h,39h,DBh,DDh,DDh,EDh,EEh,71h,31h
    db 31h,31h,31h,71h,EEh,C5h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,F2h,FDh,FBh,EEh,EEh,81h
    db 63h,63h,53h,31h,31h,31h,31h,31h,31h,61h,FCh,F5h
    db 05h,05h,F5h,FDh,FDh,24h,05h,8Dh,FCh,B4h,31h,31h
    db 31h,31h,31h,31h,39h,D8h,DBh,DBh,D2h,E7h,71h,3Ah
    db 3Ah,3Ah,3Ah,71h,E7h,C5h,45h,45h,44h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,D0h,7Eh,7Fh,ECh,EEh,59h
    db 36h,36h,31h,31h,31h,31h,31h,31h,31h,36h,3Ch,3Fh
    db 62h,62h,7Eh,7Eh,7Eh,63h,62h,57h,3Ch,38h,31h,31h
    db 31h,31h,31h,31h,31h,39h,39h,39h,38h,3Ah,A5h,E7h
    db E7h,E7h,E7h,A5h,3Ah,5Ah,E8h,E8h,D3h,44h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,CFh,65h,7Dh,EAh,EEh,59h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,3Ah
    db 65h,65h,65h,65h,65h,65h,65h,55h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db EEh,EEh,EEh,A6h,31h,5Ah,EEh,EEh,E8h,45h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,ECh,CFh,CDh,82h,82h,3Fh
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,59h,C9h,B9h
    db 3Dh,3Dh,3Dh,3Dh,3Dh,3Dh,3Dh,38h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,A6h,C9h,D3h,EEh
    db B1h,82h,82h,5Fh,31h,5Ah,EEh,EEh,E8h,45h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,75h,EEh,EEh,EEh,EEh,EAh,7Dh,65h,3Dh
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,5Ah,EEh,D1h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,B9h,EEh,EEh,EEh
    db AEh,65h,65h,5Eh,31h,5Ah,EEh,EEh,E8h,45h,33h,33h
    db 33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h,33h
    db 33h,33h,33h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,49h,5Ch,49h,33h
    db 45h,5Ch,5Ch,50h,33h,33h,50h,5Ch,46h,33h,33h,49h
    db 5Ch,49h,33h,75h,EEh,EEh,EEh,EEh,E9h,54h,40h,37h
    db 31h,31h,86h,B4h,B4h,B4h,84h,31h,31h,3Fh,60h,71h
    db B4h,B4h,B4h,B4h,B4h,5Ah,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,B9h,EEh,B1h,97h
    db B1h,BBh,BBh,9Dh,31h,5Ah,EEh,EEh,E8h,45h,33h,4Fh
    db 5Ch,45h,33h,33h,49h,5Ch,49h,33h,45h,5Ch,5Ch,50h
    db 33h,33h,50h,5Ch,10h,00h

    db C0h,93h,93h,0Fh,00h,21h,33h,33h,4Dh,68h,4Fh,33h
    db 48h,68h,68h,67h,33h,33h,67h,68h,48h,33h,33h,4Fh
    db 68h,4Dh,33h,75h,EEh,EEh,EEh,EEh,E7h,3Ah,31h,31h
    db 31h,31h,A6h,EEh,EEh,EEh,9Dh,31h,31h,31h,31h,41h
    db EEh,EEh,EEh,EEh,EEh,60h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,B9h,EEh,9Bh,65h
    db B1h,EEh,EEh,A6h,31h,5Ah,EEh,EEh,E8h,45h,33h,67h
    db 68h,48h,33h,33h,4Dh,68h,4Fh,33h,48h,68h,68h,67h
    db 33h,33h,67h,68h,10h,00h

    db C0h,93h,93h,0Fh,00h,28h,4Fh,4Fh,4Bh,49h,4Bh,4Fh
    db 4Dh,49h,49h,49h,4Fh,4Fh,49h,49h,4Dh,4Fh,4Fh,4Bh
    db 49h,4Bh,4Fh,8Eh,EEh,EEh,D3h,9Fh,9Eh,38h,31h,31h
    db 31h,31h,60h,84h,B4h,EEh,9Dh,31h,31h,31h,31h,3Ch
    db 84h,84h,84h,84h,84h,41h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,71h,84h,9Fh,B5h
    db B0h,9Fh,9Fh,85h,5Dh,64h,EEh,EEh,EBh,5Ch,4Fh,49h
    db 49h,4Dh,4Fh,4Fh,4Bh,49h,4Bh,4Fh,4Dh,49h,49h,49h
    db 4Fh,4Fh,49h,49h,09h,00h

    db C0h,93h,93h,0Fh,00h,28h,68h,68h,4Bh,33h,49h,68h
    db 5Ch,33h,33h,46h,68h,68h,46h,33h,5Ch,68h,68h,49h
    db 33h,4Bh,68h,8Fh,EEh,EEh,CFh,65h,63h,36h,31h,31h
    db 31h,31h,31h,31h,9Dh,EEh,9Dh,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db AEh,65h,65h,65h,65h,96h,EEh,EEh,EBh,6Bh,68h,46h
    db 33h,5Ch,68h,68h,4Bh,33h,49h,68h,5Ch,33h,33h,46h
    db 68h,68h,46h,33h,09h,00h

    db C0h,93h,93h,0Fh,00h,28h,68h,68h,5Ch,4Bh,5Ch,68h
    db 67h,4Bh,4Bh,4Ch,68h,68h,4Ch,4Bh,67h,68h,68h,5Ch
    db 4Bh,72h,A1h,C4h,EEh,EEh,CDh,58h,58h,35h,31h,31h
    db 31h,31h,61h,86h,9Eh,B1h,84h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,53h,56h,98h,B1h
    db 96h,65h,65h,82h,AEh,A7h,A8h,A8h,A8h,6Ah,68h,4Dh
    db 4Bh,67h,68h,68h,5Ch,4Bh,5Ch,68h,67h,4Bh,4Bh,4Ch
    db 68h,68h,4Ch,4Bh,10h,00h

    db C0h,93h,93h,0Fh,00h,28h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,A1h,EEh,EEh,EEh,EEh,C9h,31h,31h,31h,31h,31h
    db 31h,31h,A6h,EEh,AEh,65h,5Dh,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,5Fh,65h,65h,65h
    db 65h,65h,65h,9Bh,EEh,C8h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,10h,00h

    db D4h,93h,93h,0Fh,00h,28h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,A1h,EEh,D1h,BAh,BAh,B3h,71h,71h,71h,71h,71h
    db 71h,71h,A4h,BAh,85h,5Eh,53h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,5Fh,65h,96h,9Bh
    db 9Bh,9Bh,9Bh,AEh,C4h,A8h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,10h,00h

    db D7h,95h,93h,0Fh,00h,28h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,A1h,EEh,BAh,65h,65h,82h,EEh,EEh,EEh,EEh,EEh
    db EEh,EEh,9Bh,65h,56h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,5Fh,65h,BAh,EEh
    db EEh,EEh,EEh,C4h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h,68h
    db 68h,68h,68h,68h,10h,00h

    db D6h,93h,93h,0Fh,00h,28h,68h,68h,6Bh,6Dh,6Bh,68h
    db 6Ah,6Dh,6Dh,6Dh,68h,68h,6Dh,6Dh,6Ah,68h,68h,6Bh
    db 6Dh,A1h,EEh,BAh,65h,65h,80h,CCh,CCh,CCh,CCh,EFh
    db F2h,F2h,9Eh,65h,64h,61h,59h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,54h,54h,54h,62h,65h,BAh,EEh
    db D3h,D1h,D1h,A8h,68h,6Ah,6Dh,6Dh,6Dh,68h,68h,6Ch
    db 6Dh,6Ah,68h,68h,6Bh,6Dh,6Bh,68h,6Ah,6Dh,6Dh,6Dh
    db 68h,68h,6Dh,6Dh,11h,00h

    db C0h,93h,93h,0Fh,00h,28h,68h,68h,73h,7Bh,73h,68h
    db 6Eh,7Bh,7Bh,79h,68h,68h,79h,7Bh,6Dh,68h,68h,73h
    db 7Bh,B7h,EEh,BAh,65h,65h,65h,65h,65h,65h,65h,F6h
    db FFh,FFh,B1h,65h,CEh,FFh,C6h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,38h,AAh,ABh,ABh,80h,65h,BAh,EEh
    db B7h,7Bh,7Bh,73h,68h,6Dh,7Bh,7Bh,7Bh,6Ah,68h,78h
    db 7Bh,6Eh,68h,68h,73h,7Bh,73h,68h,6Eh,7Bh,7Bh,79h
    db 68h,68h,79h,7Bh,12h,00h

    db C2h,93h,93h,0Fh,00h,28h,6Bh,6Bh,73h,79h,73h,6Bh
    db 6Eh,79h,79h,78h,6Bh,6Bh,78h,79h,6Dh,6Bh,6Bh,73h
    db 79h,B7h,EEh,BAh,65h,65h,65h,65h,65h,81h,81h,F8h
    db FFh,FFh,B1h,65h,CEh,FFh,C9h,42h,42h,41h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,32h,3Ah,3Dh,ACh,AFh,AFh,80h,65h,BAh,EEh
    db B7h,79h,79h,73h,6Bh,6Dh,79h,79h,78h,6Bh,6Bh,76h
    db 79h,6Eh,6Bh,6Bh,73h,79h,73h,6Bh,6Eh,79h,79h,78h
    db 6Bh,6Bh,78h,79h,11h,00h

    db D7h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,73h,68h,6Eh,7Bh
    db 76h,68h,68h,6Bh,7Bh,7Bh,6Bh,68h,78h,7Bh,7Bh,6Eh
    db 68h,A1h,EEh,BAh,65h,65h,65h,65h,7Eh,FDh,FFh,FFh
    db FFh,FFh,B1h,65h,CEh,FFh,FFh,FFh,FFh,F0h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,3Dh,65h,7Dh,EAh,EEh,EEh,96h,65h,BAh,EEh
    db A1h,68h,68h,6Eh,7Bh,78h,68h,68h,6Ah,7Bh,7Bh,6Ch
    db 68h,76h,7Bh,7Bh,73h,68h,6Eh,7Bh,76h,68h,68h,6Bh
    db 7Bh,7Bh,6Bh,68h,10h,00h

    db D7h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,73h,68h,6Eh,7Bh
    db 76h,68h,68h,6Bh,7Bh,7Bh,6Bh,68h,78h,7Bh,7Bh,6Eh
    db 68h,A1h,EEh,BAh,65h,65h,65h,65h,7Eh,FDh,FFh,FFh
    db FFh,FFh,B1h,65h,CEh,FFh,FFh,FFh,FFh,F0h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,3Dh,65h,7Dh,EAh,EEh,EEh,96h,65h,BAh,EEh
    db A1h,68h,68h,6Eh,7Bh,78h,68h,68h,6Ah,7Bh,7Bh,6Ch
    db 68h,76h,7Bh,7Bh,73h,68h,6Eh,7Bh,76h,68h,68h,6Bh
    db 7Bh,7Bh,6Bh,68h,10h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Ah,79h,7Ah,7Bh
    db 7Bh,79h,79h,79h,7Bh,7Bh,79h,79h,7Bh,7Bh,7Bh,7Ah
    db 79h,B7h,EEh,BAh,65h,65h,7Fh,AAh,ABh,FDh,FFh,9Bh
    db 81h,81h,7Eh,65h,CEh,FFh,FFh,FFh,FFh,FDh,F8h,F3h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,59h,D3h,D1h,80h,80h,80h,7Ch,65h,BAh,EEh
    db B7h,79h,79h,7Ah,7Bh,7Bh,79h,79h,79h,7Bh,7Bh,79h
    db 79h,7Bh,7Bh,7Bh,7Ah,79h,7Ah,7Bh,7Bh,79h,79h,79h
    db 7Bh,7Bh,79h,79h,11h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,B7h,EEh,BAh,65h,65h,7Eh,ABh,ADh,FEh,FFh,96h
    db 65h,65h,65h,65h,CEh,FFh,FFh,FFh,FFh,FFh,FFh,F8h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,59h,EEh,EAh,7Dh,65h,65h,65h,65h,BAh,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,B7h,EEh,BAh,65h,65h,96h,F6h,F6h,9Bh,9Ah,BBh
    db CCh,CCh,CCh,CCh,E9h,F2h,CDh,9Ah,9Ah,9Ah,9Ah,9Eh
    db F0h,F0h,41h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 3Eh,5Fh,7Fh,EEh,EAh,7Dh,65h,65h,53h,3Eh,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,B7h,EEh,BAh,65h,65h,96h,FFh,FDh,7Eh,65h,CFh
    db EEh,EEh,EEh,EEh,EEh,EEh,B5h,65h,65h,65h,65h,81h
    db FFh,FFh,42h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 40h,65h,82h,EEh,EAh,7Dh,65h,65h,3Eh,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db E5h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,B7h,EEh,CAh,97h,97h,9Ch,B1h,B1h,7Ch,65h,CFh
    db EEh,EEh,90h,52h,2Dh,22h,4Eh,BAh,BAh,BAh,BAh,B5h
    db 87h,87h,3Ch,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 5Ah,BAh,B5h,9Bh,99h,54h,53h,53h,38h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,B7h,EEh,CDh,ABh,ABh,9Ch,65h,65h,65h,65h,CFh
    db EEh,EEh,52h,22h,17h,05h,27h,EEh,EEh,EEh,EEh,D1h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,31h
    db 60h,EEh,CFh,65h,63h,36h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,A1h,B7h,B9h,BBh,BBh,B6h,65h,65h,65h,65h,B6h
    db BCh,BCh,61h,23h,20h,20h,41h,AEh,AEh,B1h,BCh,B5h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,3Eh,58h,58h
    db 84h,EEh,CFh,65h,63h,36h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,A1h,EEh,EEh,CFh,65h,65h,65h,65h,9Ch
    db ABh,ABh,5Ah,31h,31h,31h,55h,65h,65h,80h,ABh,9Ch
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,56h,65h,65h
    db 97h,EEh,CFh,65h,63h,36h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,A1h,C4h,C4h,B9h,9Fh,9Eh,7Ch,65h,96h
    db 97h,97h,85h,84h,84h,84h,64h,5Dh,5Dh,5Eh,64h,64h
    db 31h,31h,31h,31h,31h,31h,31h,3Eh,55h,64h,9Fh,9Fh
    db AEh,B5h,AEh,5Dh,5Dh,35h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Fh,EEh,EAh,7Dh,65h,65h
    db 65h,65h,BAh,EEh,EEh,EEh,9Dh,31h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,5Dh,65h,AEh,EEh,EEh
    db BBh,65h,62h,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Fh,EEh,ECh,81h,80h,7Ch
    db 65h,65h,AEh,BBh,B9h,B4h,84h,31h,31h,31h,31h,31h
    db 31h,31h,3Eh,40h,40h,5Ah,60h,85h,97h,B0h,BBh,BBh
    db B0h,5Fh,5Dh,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Fh,EEh,ECh,ADh,ABh,7Eh
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,31h
    db 31h,31h,62h,65h,65h,BBh,EEh,EEh,EEh,B1h,65h,65h
    db 5Fh,31h,31h,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db E5h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Fh,D2h,D2h,B2h,B2h,7Fh
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,36h
    db 59h,59h,63h,65h,65h,B5h,CFh,CFh,CFh,9Fh,62h,62h
    db 5Dh,31h,31h,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Eh,EBh,EEh,82h
    db 65h,65h,65h,65h,56h,31h,31h,31h,31h,31h,31h,41h
    db EEh,EEh,80h,65h,65h,65h,65h,65h,65h,58h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A6h,EEh
    db B7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db E0h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Eh,EBh,EEh,82h
    db 65h,65h,63h,63h,56h,31h,32h,36h,36h,37h,3Ah,42h
    db EAh,EAh,7Fh,65h,65h,65h,65h,63h,63h,58h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A5h,EDh
    db B8h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Eh,EBh,EEh,82h
    db 65h,65h,53h,36h,32h,31h,53h,63h,63h,96h,E7h,D1h
    db 7Dh,7Dh,65h,65h,65h,65h,65h,55h,36h,35h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db A3h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db F4h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Eh,EBh,EEh,82h
    db 65h,65h,53h,31h,31h,31h,55h,65h,65h,96h,EEh,D3h
    db 65h,65h,65h,65h,65h,65h,65h,55h,31h,31h,31h,31h
    db 31h,31h,31h,31h,31h,31h,31h,31h,31h,31h,A0h,DDh
    db A3h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db E0h,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Fh,8Fh,C8h
    db CFh,CFh,CDh,C9h,C9h,C9h,CDh,CFh,CFh,BBh,82h,81h
    db 65h,65h,65h,65h,65h,53h,3Dh,38h,31h,31h,31h,31h
    db 70h,F6h,E2h,31h,31h,31h,31h,31h,A0h,BFh,27h,17h
    db 52h,C7h,C7h,A3h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,D2h
    db EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh,EEh,CCh,65h,65h
    db 65h,65h,65h,65h,65h,40h,31h,31h,31h,31h,31h,31h
    db 77h,FFh,F6h,31h,31h,31h,31h,31h,BDh,DDh,24h,05h
    db 2Fh,DDh,DDh,C7h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,A1h
    db A1h,A1h,CEh,EEh,EEh,EEh,EEh,EEh,EEh,CCh,65h,65h
    db 65h,65h,65h,65h,65h,40h,31h,31h,31h,87h,E2h,E2h
    db F0h,FFh,F6h,31h,38h,94h,94h,94h,27h,1Eh,10h,05h
    db 12h,1Eh,1Eh,52h,F1h,F1h,F1h,F1h,F1h,8Eh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,C8h,EEh,EEh,EEh,EEh,EEh,EEh,CCh,65h,65h
    db 65h,65h,65h,65h,65h,40h,31h,31h,31h,A0h,FFh,FFh
    db FFh,FFh,F6h,31h,39h,DBh,DDh,DDh,1Bh,05h,05h,05h
    db 05h,05h,05h,29h,FFh,FFh,FFh,FFh,FDh,8Eh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,A1h,A9h,C8h,EEh,CAh,9Fh,9Fh,99h,65h,65h
    db 65h,65h,56h,55h,55h,3Bh,31h,87h,C6h,F0h,FFh,FFh
    db FFh,FFh,F8h,90h,90h,27h,27h,27h,09h,05h,05h,05h
    db 05h,05h,05h,29h,FFh,FFh,FFh,FFh,FEh,E2h,E2h,E2h
    db E2h,E2h,E2h,E2h,B8h,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,C4h,EEh,B5h,65h,65h,65h,65h,65h
    db 65h,65h,3Ah,31h,31h,31h,31h,C6h,FFh,FFh,FFh,FFh
    db FFh,FFh,FAh,DDh,D8h,08h,05h,05h,05h,05h,05h,05h
    db 05h,05h,05h,29h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,CBh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,C4h,CBh,F2h,F6h,EFh,BBh,BBh,B5h,65h,65h
    db 65h,65h,3Ah,31h,31h,87h,A0h,F0h,FFh,FFh,FFh,FFh
    db FFh,FFh,F7h,2Fh,2Fh,05h,05h,05h,05h,05h,05h,05h
    db 09h,17h,17h,34h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,F1h,CBh,CBh,CBh,CBh,CBh,CBh,CBh
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,F1h,FFh,FFh,FFh,FFh,FFh,FFh,F3h,65h,65h
    db 65h,65h,3Ah,31h,31h,E2h,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,05h,05h
    db 17h,22h,22h,8Bh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,F9h
    db 7Bh,7Bh,7Bh,7Bh,12h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,C4h,C4h,C4h
    db C4h,C4h,F6h,FFh,FFh,FFh,FFh,FFh,FFh,F8h,B1h,B0h
    db 65h,65h,86h,87h,87h,F3h,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,05h,05h
    db 1Eh,51h,51h,91h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FBh
    db C4h,C4h,C4h,C4h,17h,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Eh,FDh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,F9h
    db 65h,65h,F9h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,05h,05h
    db 2Fh,DDh,DDh,E4h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,A1h
    db A9h,A9h,A9h,A9h,A9h,A9h,A9h,A9h,A9h,FEh,FFh,FFh
    db FFh,FFh,FAh,FAh,FCh,FFh,FFh,FFh,FFh,FFh,FFh,F9h
    db 9Ah,9Ah,F9h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,05h,05h
    db 51h,E3h,E3h,F5h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,E2h
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,DDh,F5h,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,05h,05h
    db 8Bh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,8Fh,8Fh,8Fh,F0h
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E1h,C7h,F5h,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,08h,08h
    db 8Bh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,F6h,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,8Bh,22h,94h,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,1Bh,22h
    db 94h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,F6h,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,8Bh,22h,94h,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,1Bh,22h
    db 94h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,F8h,F9h,FEh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,E3h
    db E1h,E1h,52h,22h,94h,FFh,FFh,FFh,FFh,FFh,FFh,F7h
    db 11h,11h,11h,11h,11h,D8h,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,52h,C7h
    db F5h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,2Ch,7Bh,7Bh,7Bh,7Bh,7Bh,7Bh
    db 7Bh,7Bh,7Bh,7Bh,7Bh,7Bh,F9h,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,E1h
    db DDh,DDh,51h,22h,94h,FFh,FFh,FFh,FFh,FFh,FFh,F7h
    db 05h,05h,05h,05h,05h,BFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,E4h,05h,05h,05h,05h,05h,05h,05h,89h,DDh
    db F5h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,FFh,1Ch,00h

    db DFh,95h,93h,0Fh,00h,0Bh,12h,12h,12h,12h,12h,12h
    db 12h,12h,12h,12h,12h,12h,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch
    db 1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,19h
    db 18h,18h,0Dh,08h,14h,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ah
    db 01h,01h,01h,01h,01h,16h,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch
    db 1Ch,1Ch,19h,01h,01h,01h,01h,01h,01h,01h,13h,18h
    db 1Ah,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch
    db 1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch,1Ch
    db 1Ch,1Ch,1Ch,1Ch,06h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,52h,8Ah,8Ah,8Ah,8Ah,1Ch
    db 00h,00h,00h,19h,8Ah,8Ah,34h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,1Fh,8Ah,8Ah,8Ah,8Ah,8Ah,8Ah,8Ah
    db 8Ah,8Ah,07h,00h,00h,29h,8Ah,8Ah,8Ah,8Ah,8Ah,8Ah
    db 29h,00h,00h,00h,02h,88h,8Ah,8Ah,8Ah,8Ah,8Ah,8Ah
    db 8Ah,8Ah,8Ah,26h,00h,13h,8Ah,8Ah,8Ah,8Ah,8Ah,8Ah
    db 8Ah,15h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,F5h,FFh,FFh,FFh,FFh,2Eh
    db 00h,00h,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,0Ch,00h,00h,BFh,FFh,FFh,FFh,FFh,FFh,FFh
    db BFh,00h,00h,00h,03h,FAh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,91h,00h,1Ch,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,1Fh,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,04h,2Eh,2Eh,8Ch,8Dh,8Dh,8Dh,8Dh,52h
    db 2Eh,1Ch,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,E3h,8Dh,8Dh,8Dh,8Dh,8Dh
    db 8Dh,8Dh,07h,00h,00h,BFh,FFh,D8h,8Dh,8Dh,8Dh,8Dh
    db 8Ah,2Eh,26h,00h,03h,FAh,FFh,FFh,BEh,8Dh,8Dh,8Dh
    db 8Dh,8Dh,8Dh,2Eh,00h,1Ch,FFh,FFh,FDh,8Dh,8Dh,8Dh
    db 8Dh,51h,2Eh,2Eh,1Ah,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,0Ch,00h,00h,00h,00h,8Dh
    db FFh,8Ah,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,8Dh,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,BFh,FFh,2Eh,00h,00h,00h,00h
    db 1Fh,FFh,E3h,00h,03h,FAh,FFh,FFh,1Ch,00h,00h,00h
    db 00h,00h,00h,00h,00h,1Ch,FFh,FFh,FAh,03h,00h,00h
    db 00h,BFh,FFh,FFh,51h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,26h,1Fh,1Fh,1Fh,1Fh,BFh
    db FFh,8Ah,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,BFh,1Fh,1Fh,1Fh,1Fh,1Fh
    db 1Fh,1Fh,03h,00h,00h,BFh,FFh,8Ch,1Fh,1Fh,1Fh,1Fh
    db 2Eh,BFh,8Dh,00h,03h,FAh,FFh,FFh,2Fh,1Fh,1Fh,1Fh
    db 1Fh,1Fh,1Fh,19h,00h,1Ch,FFh,FFh,FAh,03h,00h,00h
    db 00h,BFh,FFh,FFh,51h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,8Ah,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,0Ch,00h,00h,BFh,FFh,FFh,FFh,FFh,FFh,FFh
    db BFh,00h,00h,00h,03h,FAh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,91h,00h,1Ch,FFh,FFh,FAh,03h,00h,00h
    db 00h,BFh,FFh,FFh,51h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,E4h,E3h,E3h,E3h,E3h,F7h
    db FFh,8Ah,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,F7h,E3h,E3h,E3h,E3h,E3h
    db E3h,E3h,0Ah,00h,00h,BFh,FFh,F5h,E3h,E3h,E3h,E3h
    db 91h,15h,13h,00h,03h,FAh,FFh,FFh,F5h,E3h,E3h,E3h
    db E3h,E3h,E3h,8Bh,00h,1Ch,FFh,FFh,FAh,03h,00h,00h
    db 00h,BFh,FFh,FFh,51h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,0Ch,00h,00h,00h,00h,8Dh
    db FFh,8Ah,00h,26h,FFh,FFh,E3h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,8Ah,FFh,8Dh,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,BFh,FFh,2Eh,00h,00h,00h,00h
    db 1Fh,FFh,E3h,00h,03h,FAh,FFh,FFh,1Ch,00h,00h,00h
    db 00h,00h,00h,00h,00h,1Ch,FFh,FFh,FAh,03h,00h,00h
    db 00h,BFh,FFh,FFh,51h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,0Ch,00h,00h,00h,00h,8Dh
    db FFh,8Ah,00h,26h,FFh,FFh,E3h,03h,03h,03h,03h,03h
    db 03h,03h,02h,00h,8Ah,FFh,8Dh,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,BFh,FFh,2Eh,00h,00h,00h,00h
    db 1Fh,FFh,E3h,00h,03h,FAh,FFh,FFh,1Dh,03h,03h,03h
    db 03h,03h,03h,02h,00h,1Ch,FFh,FFh,FAh,07h,03h,03h
    db 03h,BEh,FAh,FAh,51h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,0Ch,00h,00h,00h,00h,8Dh
    db FFh,8Ah,00h,26h,FFh,FFh,FEh,FAh,FAh,FAh,FAh,FAh
    db FAh,FAh,26h,00h,8Ah,FFh,8Dh,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,BFh,FFh,2Eh,00h,00h,00h,00h
    db 1Fh,FFh,E3h,00h,03h,FAh,FFh,FFh,FCh,FAh,FAh,FAh
    db FAh,FAh,FAh,91h,00h,1Ch,FFh,FFh,FFh,FAh,FAh,FAh
    db FAh,1Fh,03h,03h,02h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,0Ch,FFh,FFh,0Ch,00h,00h,00h,00h,8Dh
    db FFh,8Ah,00h,26h,FFh,FFh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,26h,00h,8Ah,FFh,8Dh,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,BFh,FFh,2Eh,00h,00h,00h,00h
    db 1Fh,FFh,E3h,00h,03h,FAh,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,FFh,FFh,91h,00h,1Ch,FFh,FFh,FFh,FFh,FFh,FFh
    db FFh,1Fh,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,02h,15h,15h,02h,00h,00h,00h,00h,0Ch
    db 15h,0Ah,00h,07h,15h,15h,15h,15h,15h,15h,15h,15h
    db 15h,15h,07h,00h,0Ah,15h,0Ch,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,0Fh,15h,07h,00h,00h,00h,00h
    db 06h,15h,13h,00h,00h,15h,15h,15h,15h,15h,15h,15h
    db 15h,15h,15h,0Fh,00h,04h,15h,15h,15h,15h,15h,15h
    db 15h,06h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,0Fh,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
    db 00h,00h,00h,00h,00h,00h

    db DFh,95h,93h,51h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h,30h
    db 30h,30h,30h,30h,30h,30h

    db DFh,95h,93h,D6h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h,D7h
    db D7h,D7h,D7h,D7h,D7h,D7h

    db DFh,95h,93h,D4h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h,D5h
    db D5h,D5h,D5h,D5h,D5h,D5h
