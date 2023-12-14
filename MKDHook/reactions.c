#include "reactions.h"
#include "mkdeception.h"
#include "mips.h"
#include "ps2mem.h"
#pragma once

reaction_table_entry reaction_table[TOTAL_REACTIONS] = {
	{TYPE_REACTIONS_FUNCTION, 32, 0, 0, 1},//   0
	{TYPE_REACTIONS_FUNCTION, 22, 3, 2, 257},//   1
	{TYPE_REACTIONS_FUNCTION, 24, 3, 1, 769},//   2
	{TYPE_FUNCTION_CALL, 0x214DE0, 5, 2, 257},//   3
	{TYPE_FUNCTION_CALL, 0x214C50, 3, 2, 258},//   4
	{TYPE_FUNCTION_CALL, 0x214A60, 5, 2, 257},//   5
	{TYPE_REACTIONS_FUNCTION, 37, 5, 2, 258},//   6
	{TYPE_REACTIONS_FUNCTION, 30, 5, 2, 274},//   7
	{TYPE_REACTIONS_FUNCTION, 29, 5, 2, 274},//   8
	{TYPE_REACTIONS_FUNCTION, 27, 3, 1, 769},//   9
	{TYPE_REACTIONS_FUNCTION, 34, 0, 1, 513},//  10
	{TYPE_REACTIONS_FUNCTION, 36, 0, 1, 513},//  11
	{TYPE_REACTIONS_FUNCTION, 35, 0, 1, 513},//  12
	{TYPE_REACTIONS_FUNCTION, 23, 3, 2, 257},//  13
	{TYPE_REACTIONS_FUNCTION, 33, 3, 1, 769},//  14
	{TYPE_REACTIONS_FUNCTION, 26, 5, 1, 770},//  15
	{TYPE_REACTIONS_FUNCTION, 31, 0, 0, 1},//  16
	{TYPE_REACTIONS_FUNCTION, 25, 3, 0, 769},//  17
	{TYPE_REACTIONS_FUNCTION, 25, 3, 1, 769},//  18
	{TYPE_REACTIONS_FUNCTION, 28, 3, 1, 769},//  19
	{TYPE_REACTIONS_FUNCTION, 91, 0, 2, 257},//  20
	{TYPE_FUNCTION_CALL, 0x2152E0, 3, 2, 257},//  21
	{TYPE_FUNCTION_CALL, 0x2152E0, 3, 1, 769},//  22
	{TYPE_FUNCTION_CALL, 0x2101F0, 3, 2, 257},//  23
	{TYPE_FUNCTION_CALL, 0x215260, 3, 1, 769},//  24
	{TYPE_REACTIONS_FUNCTION, 89, 5, 0, 274},//  25
	{TYPE_REACTIONS_FUNCTION, 88, 5, 0, 274},//  26
	{TYPE_REACTIONS_FUNCTION, 90, 5, 0, 274},//  27
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  28
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  29
	{TYPE_REACTIONS_FUNCTION, 1, 0, 0, 1},//  30
	{TYPE_REACTIONS_FUNCTION, 9, 0, 0, 1},//  31
	{TYPE_REACTIONS_FUNCTION, 2, 0, 1, 513},//  32
	{TYPE_REACTIONS_FUNCTION, 3, 0, 1, 513},//  33
	{TYPE_REACTIONS_FUNCTION, 5, 0, 1, 513},//  34
	{TYPE_REACTIONS_FUNCTION, 4, 0, 1, 513},//  35
	{TYPE_REACTIONS_FUNCTION, 8, 0, 1, 513},//  36
	{TYPE_REACTIONS_FUNCTION, 6, 0, 1, 513},//  37
	{TYPE_REACTIONS_FUNCTION, 7, 0, 1, 513},//  38
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  39
	{TYPE_REACTIONS_FUNCTION, 17, 3, 0, 257},//  40
	{TYPE_REACTIONS_FUNCTION, 16, 3, 2, 257},//  41
	{TYPE_REACTIONS_FUNCTION, 11, 3, 1, 769},//  42
	{TYPE_REACTIONS_FUNCTION, 14, 3, 2, 257},//  43
	{TYPE_REACTIONS_FUNCTION, 10, 3, 2, 257},//  44
	{TYPE_REACTIONS_FUNCTION, 10, 3, 1, 769},//  45
	{TYPE_REACTIONS_FUNCTION, 16, 3, 1, 769},//  46
	{TYPE_REACTIONS_FUNCTION, 14, 3, 1, 769},//  47
	{TYPE_REACTIONS_FUNCTION, 15, 3, 2, 257},//  48
	{TYPE_REACTIONS_FUNCTION, 13, 3, 1, 769},//  49
	{TYPE_FUNCTION_CALL, 0x2123B0, 5, 2, 834},//  50
	{TYPE_REACTIONS_FUNCTION, 19, 5, 2, 834},//  51
	{TYPE_REACTIONS_FUNCTION, 21, 5, 2, 834},//  52
	{TYPE_REACTIONS_FUNCTION, 20, 5, 2, 834},//  53
	{TYPE_REACTIONS_FUNCTION, 18, 5, 2, 769},//  54
	{TYPE_REACTIONS_FUNCTION, 18, 5, 1, 769},//  55
	{TYPE_REACTIONS_FUNCTION, 12, 5, 2, 769},//  56
	{TYPE_REACTIONS_FUNCTION, 12, 5, 1, 769},//  57
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  58
	{TYPE_REACTIONS_FUNCTION, 67, 4, 2, 274},//  59
	{TYPE_REACTIONS_FUNCTION, 66, 4, 2, 274},//  60
	{TYPE_REACTIONS_FUNCTION, 65, 4, 2, 274},//  61
	{TYPE_REACTIONS_FUNCTION, 70, 4, 2, 274},//  62
	{TYPE_REACTIONS_FUNCTION, 68, 4, 2, 274},//  63
	{TYPE_REACTIONS_FUNCTION, 63, 4, 1, 658},//  64
	{TYPE_REACTIONS_FUNCTION, 64, 4, 0, 658},//  65
	{TYPE_FUNCTION_CALL, 0x2128C0, 5, 0, 2},//  66
	{TYPE_REACTIONS_FUNCTION, 73, 5, 1, 530},//  67
	{TYPE_REACTIONS_FUNCTION, 74, 0, 0, 338},//  68
	{TYPE_REACTIONS_FUNCTION, 77, 5, 0, 1},//  69
	{TYPE_REACTIONS_FUNCTION, 76, 5, 2, 65},//  70
	{TYPE_REACTIONS_FUNCTION, 72, 4, 1, 530},//  71
	{TYPE_REACTIONS_FUNCTION, 62, 4, 1, 594},//  72
	{TYPE_REACTIONS_FUNCTION, 69, 4, 2, 274},//  73
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  74
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  75
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  76
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  77
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  78
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  79
	{TYPE_FUNCTION_CALL, 0x2143F0, 0, 0, 66},//  80
	{TYPE_FUNCTION_CALL, 0x2145F0, 5, 0, 66},//  81
	{TYPE_FUNCTION_CALL, 0x213FF0, 5, 0, 66},//  82
	{TYPE_REACTIONS_FUNCTION, 40, 5, 0, 2},//  83
	{TYPE_REACTIONS_FUNCTION, 42, 5, 2, 2},//  84
	{TYPE_FUNCTION_CALL, 0x2141F0, 5, 0, 66},//  85
	{TYPE_REACTIONS_FUNCTION, 41, 5, 2, 66},//  86
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  87
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  88
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  89
	{TYPE_REACTIONS_FUNCTION, 86, 0, 1, 513},//  90
	{TYPE_REACTIONS_FUNCTION, 87, 0, 1, 513},//  91
	{TYPE_REACTIONS_FUNCTION, 84, 3, 1, 513},//  92
	{TYPE_REACTIONS_FUNCTION, 79, 3, 0, 513},//  93
	{TYPE_REACTIONS_FUNCTION, 82, 3, 1, 513},//  94
	{TYPE_REACTIONS_FUNCTION, 78, 3, 0, 513},//  95
	{TYPE_REACTIONS_FUNCTION, 81, 3, 1, 513},//  96
	{TYPE_REACTIONS_FUNCTION, 85, 3, 1, 513},//  97
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  98
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},//  99
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 100
	{TYPE_REACTIONS_FUNCTION, 46, 5, 2, 978},// 101
	{TYPE_REACTIONS_FUNCTION, 59, 5, 2, 978},// 102
	{TYPE_REACTIONS_FUNCTION, 57, 5, 2, 978},// 103
	{TYPE_REACTIONS_FUNCTION, 52, 5, 1, 978},// 104
	{TYPE_REACTIONS_FUNCTION, 53, 5, 1, 978},// 105
	{TYPE_REACTIONS_FUNCTION, 56, 5, 0, 978},// 106
	{TYPE_REACTIONS_FUNCTION, 47, 4, 2, 977},// 107
	{TYPE_REACTIONS_FUNCTION, 54, 5, 0, 978},// 108
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 109
	{TYPE_REACTIONS_FUNCTION, 46, 5, 2, 466},// 110
	{TYPE_REACTIONS_FUNCTION, 59, 5, 2, 466},// 111
	{TYPE_REACTIONS_FUNCTION, 57, 5, 2, 466},// 112
	{TYPE_REACTIONS_FUNCTION, 52, 5, 1, 466},// 113
	{TYPE_REACTIONS_FUNCTION, 53, 5, 1, 466},// 114
	{TYPE_REACTIONS_FUNCTION, 56, 5, 0, 466},// 115
	{TYPE_REACTIONS_FUNCTION, 47, 4, 2, 465},// 116
	{TYPE_REACTIONS_FUNCTION, 54, 5, 0, 466},// 117
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 118
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 119
	{TYPE_FUNCTION_CALL, 0x211400, 0, 2, 1},// 120
	{TYPE_FUNCTION_CALL, 0x211340, 0, 2, 1},// 121
	{TYPE_FUNCTION_CALL, 0x211070, 0, 2, 1},// 122
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 123
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 124
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 125
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 126
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 127
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 128
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 129
	{TYPE_REACTIONS_FUNCTION, 50, 3, 1, 513},// 130
	{TYPE_REACTIONS_FUNCTION, 48, 3, 1, 514},// 131
	{TYPE_REACTIONS_FUNCTION, 49, 3, 1, 514},// 132
	{TYPE_REACTIONS_FUNCTION, 51, 3, 1, 513},// 133
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 134
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 135
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 136
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 137
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 138
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 139
	{TYPE_FUNCTION_CALL, 0x214900, 0, 0, 1},// 140
	{TYPE_FUNCTION_CALL, 0x2147A0, 0, 0, 1},// 141
	{TYPE_REACTIONS_FUNCTION, 39, 0, 1, 513},// 142
	{TYPE_REACTIONS_FUNCTION, 43, 0, 1, 513},// 143
	{TYPE_REACTIONS_FUNCTION, 44, 3, 2, 2},// 144
	{TYPE_REACTIONS_FUNCTION, 44, 3, 1, 514},// 145
	{TYPE_REACTIONS_FUNCTION, 45, 3, 2, 2},// 146
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 147
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 148
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 149
	{TYPE_FUNCTION_CALL, 0x213DA0, 5, 2, 322},// 150
	{TYPE_FUNCTION_CALL, 0x213BB0, 5, 2, 322},// 151
	{TYPE_REACTIONS_FUNCTION, 145, 0, 0, 82},// 152
	{TYPE_FUNCTION_CALL, 0x2139D0, 5, 2, 322},// 153
	{TYPE_REACTIONS_FUNCTION, 116, 3, 2, 5},// 154
	{TYPE_REACTIONS_FUNCTION, 117, 3, 2, 5},// 155
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 156
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 157
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 158
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 159
	{TYPE_FUNCTION_CALL, 0x215BE0, 5, 1, 18},// 160
	{TYPE_FUNCTION_CALL, 0x2160C0, 5, 1, 1},// 161
	{TYPE_REACTIONS_FUNCTION, 115, 5, 1, 513},// 162
	{TYPE_FUNCTION_CALL, 0x2168B0, 3, 1, 18},// 163
	{TYPE_FUNCTION_CALL, 0x216710, 0, 1, 18},// 164
	{TYPE_FUNCTION_CALL, 0x2161F0, 0, 0, 10},// 165
	{TYPE_FUNCTION_CALL, 0x2158F0, 0, 0, 18},// 166
	{TYPE_FUNCTION_CALL, 0x2155F0, 0, 0, 18},// 167
	{TYPE_FUNCTION_CALL, 0x0, 0, 0, 2},// 168
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 169
	{TYPE_REACTIONS_FUNCTION, 110, 0, 0, 18},// 170
	{TYPE_FUNCTION_CALL, 0x215100, 0, 1, 1},// 171
	{TYPE_FUNCTION_CALL, 0x214FB0, 0, 1, 1},// 172
	{TYPE_REACTIONS_FUNCTION, 109, 0, 0, 1},// 173
	{TYPE_REACTIONS_FUNCTION, 108, 0, 0, 273},// 174
	{TYPE_REACTIONS_FUNCTION, 107, 0, 1, 1},// 175
	{TYPE_REACTIONS_FUNCTION, 105, 0, 1, 2},// 176
	{TYPE_REACTIONS_FUNCTION, 104, 0, 2, 1},// 177
	{TYPE_REACTIONS_FUNCTION, 114, 0, 1, 513},// 178
	{TYPE_FUNCTION_CALL, 0x215A60, 0, 2, 1},// 179
	{TYPE_REACTIONS_FUNCTION, 101, 3, 0, 18},// 180
	{TYPE_FUNCTION_CALL, 0x210A40, 0, 0, 50},// 181
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 182
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 183
	{TYPE_REACTIONS_FUNCTION, 92, 0, 1, 1},// 184
	{TYPE_REACTIONS_FUNCTION, 100, 0, 2, 1},// 185
	{TYPE_FUNCTION_CALL, 0x0, 0, 2, 18},// 186
	{TYPE_FUNCTION_CALL, 0x2103F0, 0, 0, 2},// 187
	{TYPE_FUNCTION_CALL, 0x216A40, 0, 1, 1},// 188
	{TYPE_REACTIONS_FUNCTION, 96, 0, 0, 1},// 189
	{TYPE_FUNCTION_CALL, 0x210E40, 0, 0, 1},// 190
	{TYPE_FUNCTION_CALL, 0x210DE0, 0, 0, 1},// 191
	{TYPE_REACTIONS_FUNCTION, 99, 0, 1, 17},// 192
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 193
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 194
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 195
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 196
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 197
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 198
	{TYPE_REACTIONS_FUNCTION, 93, 0, 1, 1},// 199
	{TYPE_REACTIONS_FUNCTION, 94, 0, 0, 82},// 200
	{TYPE_REACTIONS_FUNCTION, 95, 0, 0, 82},// 201
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 202
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 203
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 204
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 205
	{TYPE_FUNCTION_CALL, 0x216A90, 0, 1, 18},// 206
	{TYPE_REACTIONS_FUNCTION, 113, 0, 0, 18},// 207
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 208
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 209
	{TYPE_REACTIONS_FUNCTION, 98, 0, 0, 18},// 210
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 211
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 212
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 213
	{TYPE_REACTIONS_FUNCTION, 112, 3, 1, 513},// 214
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 215
	{TYPE_FUNCTION_CALL, 0x212610, 5, 0, 18},// 216
	{TYPE_FUNCTION_CALL, 0x210F10, 0, 0, 1},// 217
	{TYPE_FUNCTION_CALL, 0x210AF0, 0, 1, 18},// 218
	{TYPE_FUNCTION_CALL, 0x212FC0, 5, 0, 1},// 219
	{TYPE_FUNCTION_CALL, 0x2130C0, 5, 0, 1},// 220
	{TYPE_REACTIONS_FUNCTION, 103, 100, 0, 1},// 221
	{TYPE_REACTIONS_FUNCTION, 62, 1, 1, 530},// 222
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 223
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 224
	{TYPE_FUNCTION_CALL, 0x0, 0, 0, 18},// 225
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 226
	{TYPE_FUNCTION_CALL, 0x210510, 0, 0, 1},// 227
	{TYPE_REACTIONS_FUNCTION, 122, 0, 0, 2},// 228
	{TYPE_FUNCTION_CALL, 0x13FD80, 0, 0, 1},// 229
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 230
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 231
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 232
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 233
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 234
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 235
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 236
	{TYPE_FUNCTION_CALL, 0x20FBA0, 5, 0, 18},// 237
	{TYPE_REACTIONS_FUNCTION, 121, 3, 1, 18},// 238
	{TYPE_REACTIONS_FUNCTION, 60, 5, 2, 210},// 239
	{TYPE_FUNCTION_CALL, 0x213240, 5, 0, 18},// 240
	{TYPE_FUNCTION_CALL, 0x2135A0, 5, 0, 274},// 241
	{TYPE_FUNCTION_CALL, 0x211810, 5, 0, 18},// 242
	{TYPE_FUNCTION_CALL, 0x211780, 5, 0, 18},// 243
	{TYPE_FUNCTION_CALL, 0x211700, 5, 0, 18},// 244
	{TYPE_FUNCTION_CALL, 0x211680, 5, 0, 18},// 245
	{TYPE_FUNCTION_CALL, 0x210FF0, 5, 0, 18},// 246
	{TYPE_REACTIONS_FUNCTION, 125, 3, 1, 18},// 247
	{TYPE_REACTIONS_FUNCTION, 126, 5, 1, 18},// 248
	{TYPE_REACTIONS_FUNCTION, 127, 5, 1, 2},// 249
	{TYPE_REACTIONS_FUNCTION, 129, 5, 1, 1},// 250
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 251
	{TYPE_FUNCTION_CALL, 0x2138E0, 5, 0, 18},// 252
	{TYPE_REACTIONS_FUNCTION, 128, 5, 1, 2},// 253
	{TYPE_FUNCTION_CALL, 0x2123B0, 5, 2, 338},// 254
	{TYPE_FUNCTION_CALL, 0x216180, 0, 1, 1},// 255
	{TYPE_REACTIONS_FUNCTION, 130, 0, 1, 18},// 256
	{TYPE_REACTIONS_FUNCTION, 131, 5, 1, 18},// 257
	{TYPE_REACTIONS_FUNCTION, 133, 0, 1, 18},// 258
	{TYPE_REACTIONS_FUNCTION, 132, 0, 1, 18},// 259
	{TYPE_REACTIONS_FUNCTION, 61, 5, 0, 82},// 260
	{TYPE_FUNCTION_CALL, 0x211FB0, 5, 2, 338},// 261
	{TYPE_FUNCTION_CALL, 0x211DB0, 5, 2, 66},// 262
	{TYPE_REACTIONS_FUNCTION, 102, 0, 2, 1},// 263
	{TYPE_REACTIONS_FUNCTION, 106, 0, 1, 18},// 264
	{TYPE_FUNCTION_CALL, 0x20FBA0, 0, 0, 1},// 265
	{TYPE_REACTIONS_FUNCTION, 134, 3, 1, 1},// 266
	{TYPE_REACTIONS_FUNCTION, 135, 3, 1, 1},// 267
	{TYPE_REACTIONS_FUNCTION, 136, 3, 1, 1},// 268
	{TYPE_REACTIONS_FUNCTION, 137, 3, 1, 257},// 269
	{TYPE_REACTIONS_FUNCTION, 38, 3, 1, 1},// 270
	{TYPE_FUNCTION_CALL, 0x213380, 5, 0, 18},// 271
	{TYPE_REACTIONS_FUNCTION, 138, 3, 1, 1},// 272
	{TYPE_FUNCTION_CALL, 0x2152E0, 3, 1, 272},// 273
	{TYPE_REACTIONS_FUNCTION, 139, 5, 1, 18},// 274
	{TYPE_REACTIONS_FUNCTION, 140, 5, 1, 18},// 275
	{TYPE_2, 32, 5, 1, 2},// 276
	{TYPE_2, 33, 0, 1, 1},// 277
	{TYPE_2, 34, 3, 1, 1},// 278
	{TYPE_2, 36, 3, 1, 1},// 279
	{TYPE_2, 37, 0, 1, 1},// 280
	{TYPE_REACTIONS_FUNCTION, 141, 5, 1, 1},// 281
	{TYPE_SCRIPT_FUNCTION, 19, 0, 0, 338},// 282
	{TYPE_SCRIPT_FUNCTION, 27, 0, 0, 82},// 283
	{TYPE_SCRIPT_FUNCTION, 34, 0, 0, 82},// 284
	{TYPE_SCRIPT_FUNCTION, 42, 0, 0, 338},// 285
	{TYPE_SCRIPT_FUNCTION, 23, 0, 0, 82},// 286
	{TYPE_SCRIPT_FUNCTION, 34, 0, 0, 82},// 287
	{TYPE_SCRIPT_FUNCTION, 27, 0, 0, 82},// 288
	{TYPE_SCRIPT_FUNCTION, 35, 0, 0, 82},// 289
	{TYPE_SCRIPT_FUNCTION, 28, 0, 0, 82},// 290
	{TYPE_SCRIPT_FUNCTION, 28, 0, 0, 65},// 291
	{TYPE_SCRIPT_FUNCTION, 27, 0, 0, 65},// 292
	{TYPE_SCRIPT_FUNCTION, 25, 0, 0, 65},// 293
	{TYPE_SCRIPT_FUNCTION, 40, 0, 1, 65},// 294
	{TYPE_SCRIPT_FUNCTION, 29, 0, 0, 82},// 295
	{TYPE_SCRIPT_FUNCTION, 34, 0, 0, 68},// 296
	{TYPE_SCRIPT_FUNCTION, 38, 0, 0, 82},// 297
	{TYPE_SCRIPT_FUNCTION, 39, 0, 1, 4},// 298
	{TYPE_SCRIPT_FUNCTION, 29, 0, 1, 82},// 299
	{TYPE_SCRIPT_FUNCTION, 30, 0, 0, 338},// 300
	{TYPE_SCRIPT_FUNCTION, 32, 0, 2, 1},// 301
	{TYPE_2, 35, 3, 1, 1},// 302
	{TYPE_SCRIPT_FUNCTION, 6, 0, 0, 82},// 303
	{TYPE_SCRIPT_FUNCTION, 27, 0, 0, 82},// 304
	{TYPE_FUNCTION_CALL, 0x1464F0, 0, 0, 2},// 305
	{TYPE_SCRIPT_FUNCTION, 18, 0, 0, 82},// 306
	{TYPE_FUNCTION_CALL, 0x210990, 0, 0, 50},// 307
	{TYPE_REACTIONS_FUNCTION, 71, 4, 2, 274},// 308
	{TYPE_FUNCTION_CALL, 0x213800, 5, 0, 18},// 309
	{TYPE_REACTIONS_FUNCTION, 97, 4, 2, 18},// 310
	{TYPE_FUNCTION_CALL, 0x212150, 0, 2, 338},// 311
	{TYPE_SCRIPT_FUNCTION, 27, 0, 0, 82},// 312
	{TYPE_SCRIPT_FUNCTION, 57, 0, 1, 18},// 313
//	MKU
	{ TYPE_SCRIPT_FUNCTION , 22, 0, 0, 0x52 }, // 314
	// frost backflip
	{ TYPE_REACTIONS_FUNCTION, 150, 5, 2, 0x1D2 }, // 315
	{ TYPE_REACTIONS_FUNCTION, 80, 0, 0, 0x152 },// 316
	// jax drop kick hit
	{ TYPE_REACTIONS_FUNCTION, 148, 0, 0, 0x152 },// 317
    // fan lift
	{ TYPE_REACTIONS_FUNCTION, 146, 3, 1, 0x18 },// 318
	// blaze step kick
	{ TYPE_REACTIONS_FUNCTION, 151, 0, 0, 0x152 },// 319
	// blaze charge
	{ TYPE_REACTIONS_FUNCTION, 152, 5, 2, 0x102 }, // 320
	// jax gun fire
	{ TYPE_REACTIONS_FUNCTION, 149, 0, 2, 1 },// 321
	// pretty kick hit 2
	{ TYPE_REACTIONS_FUNCTION, 147, 3, 1, 0x301 },//322 
	{ TYPE_TRANSFER, 0, 0, 0, 0 }, // 323
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 324
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 325
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 326
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 327
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 328
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 329
	{ TYPE_TRANSFER, 0, 0, 0, 0 },// 330
// END OF MKU
	// frost tongbei 2 NOTE: this replaces some unused reaction slot in MKU but i'd rather add it as new to not break anything
	{ TYPE_REACTIONS_FUNCTION, 18, 5, 2, 0x201 }, // 331
	// wrestling throws from mka
	{ TYPE_REACTIONS_FUNCTION, 153, 0, 0, 0x52 }, // 332
	{ TYPE_REACTIONS_FUNCTION, 154, 0, 0, 0x52 }, // 333
	// wrestling foot throw
	{ TYPE_REACTIONS_FUNCTION, 155, 5, 2, 0x201 }, // 334
	{ TYPE_REACTIONS_FUNCTION, 156, 5, 2, 0x201 }, // 335
	// sareena throw
	{ TYPE_REACTIONS_FUNCTION, 157, 0, 0, 0x11 }, // 336
	// quan stomp
	{ TYPE_REACTIONS_FUNCTION, 158, 4, 2, 0x12 }, // 337
	// quan skull
	{ TYPE_REACTIONS_FUNCTION, 159, 0, 0, 1 }, // 338
	// quan swords
	{ TYPE_REACTIONS_FUNCTION, 160, 5, 1, 769 },//  339
	// shang soul steal
	{ TYPE_REACTIONS_FUNCTION, 27, 0, 0, 1 },//  340
	// shang balls
	{ TYPE_REACTIONS_FUNCTION, 18, 0, 0, 1 },//  341
	// step kick throw
	{ TYPE_FUNCTION_CALL, 0x2123B0, 5, 2, 834 },//  342
	// cage throw
	{ TYPE_REACTIONS_FUNCTION, 162, 0, 0, 0x11 }, // 343
	{ TYPE_REACTIONS_FUNCTION, 163, 0, 0, 0x11 }, // 344
	// drahmin projectile
	{ TYPE_FUNCTION_CALL, 0x215260, 0, 0, 1 },//  345
};

int onaga_remap_table[TOTAL_REACTIONS] = {
	277, //   0
	277, //   1
	277, //   2
	302, //   3
	278, //   4
	278, //   5
	302, //   6
	302, //   7
	302, //   8
	278, //   9
	277, //  10
	277, //  11
	277, //  12
	277, //  13
	277, //  14
	302, //  15
	277, //  16
	277, //  17
	277, //  18
	277, //  19
	277, //  20
	278, //  21
	278, //  22
	278, //  23
	278, //  24
	302, //  25
	302, //  26
	277, //  27
	277, //  28
	277, //  29
	277, //  30
	277, //  31
	277, //  32
	277, //  33
	277, //  34
	277, //  35
	277, //  36
	277, //  37
	277, //  38
	277, //  39
	279, //  40
	279, //  41
	279, //  42
	276, //  43
	276, //  44
	279, //  45
	279, //  46
	279, //  47
	279, //  48
	279, //  49
	279, //  50
	279, //  51
	279, //  52
	279, //  53
	279, //  54
	279, //  55
	279, //  56
	279, //  57
	279, //  58
	279, //  59
	279, //  60
	279, //  61
	279, //  62
	279, //  63
	279, //  64
	276, //  65
	279, //  66
	279, //  67
	279, //  68
	279, //  69
	279, //  70
	279, //  71
	279, //  72
	279, //  73
	279, //  74
	279, //  75
	279, //  76
	279, //  77
	279, //  78
	279, //  79
	280, //  80
	280, //  81
	280, //  82
	280, //  83
	280, //  84
	280, //  85
	280, //  86
	280, //  87
	280, //  88
	280, //  89
	279, //  90
	279, //  91
	279, //  92
	279, //  93
	279, //  94
	279, //  95
	279, //  96
	279, //  97
	279, //  98
	279, //  99
	276, // 100
	276, // 101
	276, // 102
	279, // 103
	279, // 104
	276, // 105
	276, // 106
	276, // 107
	276, // 108
	276, // 109
	276, // 110
	276, // 111
	276, // 112
	276, // 113
	276, // 114
	276, // 115
	276, // 116
	276, // 117
	276, // 118
	276, // 119
	276, // 120
	-1, // 121
	276, // 122
	276, // 123
	276, // 124
	276, // 125
	276, // 126
	276, // 127
	276, // 128
	276, // 129
	276, // 130
	276, // 131
	276, // 132
	276, // 133
	276, // 134
	276, // 135
	276, // 136
	276, // 137
	276, // 138
	276, // 139
	280, // 140
	280, // 141
	280, // 142
	280, // 143
	280, // 144
	280, // 145
	280, // 146
	280, // 147
	280, // 148
	280, // 149
	280, // 150
	280, // 151
	280, // 152
	280, // 153
	-1, // 154
	-1, // 155
	280, // 156
	280, // 157
	280, // 158
	280, // 159
	278, // 160
	278, // 161
	276, // 162
	278, // 163
	278, // 164
	278, // 165
	278, // 166
	278, // 167
	278, // 168
	278, // 169
	278, // 170
	278, // 171
	278, // 172
	278, // 173
	278, // 174
	278, // 175
	278, // 176
	278, // 177
	278, // 178
	278, // 179
	278, // 180
	278, // 181
	278, // 182
	278, // 183
	278, // 184
	278, // 185
	278, // 186
	278, // 187
	278, // 188
	278, // 189
	278, // 190
	278, // 191
	278, // 192
	278, // 193
	278, // 194
	278, // 195
	278, // 196
	278, // 197
	278, // 198
	278, // 199
	278, // 200
	278, // 201
	278, // 202
	278, // 203
	278, // 204
	278, // 205
	278, // 206
	278, // 207
	278, // 208
	278, // 209
	279, // 210
	278, // 211
	278, // 212
	278, // 213
	278, // 214
	278, // 215
	278, // 216
	278, // 217
	278, // 218
	278, // 219
	278, // 220
	278, // 221
	278, // 222
	278, // 223
	278, // 224
	278, // 225
	278, // 226
	278, // 227
	278, // 228
	278, // 229
	278, // 230
	278, // 231
	278, // 232
	278, // 233
	278, // 234
	278, // 235
	278, // 236
	278, // 237
	278, // 238
	276, // 239
	278, // 240
	278, // 241
	278, // 242
	278, // 243
	278, // 244
	278, // 245
	278, // 246
	278, // 247
	278, // 248
	278, // 249
	278, // 250
	278, // 251
	278, // 252
	278, // 253
	279, // 254
	278, // 255
	278, // 256
	278, // 257
	280, // 258
	278, // 259
	279, // 260
	278, // 261
	276, // 262
	277, // 263
	280, // 264
	280, // 265
	-1, // 266
	-1, // 267
	-1, // 268
	-1, // 269
	277, // 270
	277, // 271
	277, // 272
	278, // 273
	277, // 274
	277, // 275
	277, // 276
	277, // 277
	277, // 278
	277, // 279
	277, // 280
	277, // 281
	277, // 282
	277, // 283
	277, // 284
	277, // 285
	277, // 286
	277, // 287
	277, // 288
	277, // 289
	277, // 290
	277, // 291
	277, // 292
	277, // 293
	277, // 294
	277, // 295
	277, // 296
	277, // 297
	277, // 298
	277, // 299
	277, // 300
	277, // 301
	277, // 302
	277, // 303
	277, // 304
	277, // 305
	277, // 306
	277, // 307
	278, // 308
	278, // 309
	278, // 310
	278, // 311
	278, // 312
	0,   // 313
	-1, // 314
	-1, // 315
	-1, // 316
	-1, // 317
	278, // 318 (kitana fan lift)
	279, // 319 (blaze grab)
	279, // 320 (blaze charge)
	278, // 321
	279, // 322 ( kitana pretty kick hit 2)
	-1, // 323
	-1, // 324
	-1, // 325
	-1, // 326
	-1, // 327
	-1, // 328
	-1, // 329
	-1, // 330
	279, // 331
	278, // 332
	278, // 333
	278, // 334
	278, // 335
	278, // 336
	278, // 337
	278, // 338
	279, // 339
	278, // 340
	278, // 341
	278, // 342
	278, // 343
	278, // 344
	278, // 345
};

static int goro_lower_arms_atk[] = {
	5,
	8,
	0xFFFFFFFF,
	4,
	7,
	0
};

static int attack_region_list[] = {
	0,
	0x594580,
	0x594590,
	0x5945A0,
	0x5945B0,
	0x5945C0,
	0x5945E0,
	0x594600,
	0x594620,
	0x594640,
	0x594660,
	0x594690,
	0x5946C0,
	0x5946F0,
	0x594718,
	(int)&goro_lower_arms_atk[0]
};

void init_reactions_hook()
{
	int val;
	val = (int)&reaction_table[0];

	short num = TOTAL_REACTIONS;
	patchShort(0x2418DC, num);

	// field0
	patchInt(0x20E54C, lui(a0, HIWORD(val)));
	patchInt(0x20E554, ori(a0, a0, LOWORD(val)));

	patchInt(0x20F3AC, lui(v0, HIWORD(val)));
	patchInt(0x20F3B4, ori(v0, v0, LOWORD(val)));

	patchInt(0x20F498, lui(v0, HIWORD(val)));
	patchInt(0x20F4A0, ori(v0, v0, LOWORD(val)));

	patchInt(0x20FB38, lui(v0, HIWORD(val)));
	patchInt(0x20FB40, ori(v0, v0, LOWORD(val)));

	val += 8;

	//field8
	patchInt(0x20F0C8, lui(v1, HIWORD(val)));
	patchInt(0x20F0C8 + 4, ori(v1, v1, LOWORD(val)));

	patchInt(0x20F418, lui(v1, HIWORD(val)));
	patchInt(0x20F950 + 4, ori(v1, v1, LOWORD(val)));

	patchInt(0x20FAE0, lui(v0, HIWORD(val)));
	patchInt(0x20FAE8, ori(v0, v0, LOWORD(val)));


	val += 4;

	//field12
	patchInt(0x20E7C4, lui(v1, HIWORD(val)));
	patchInt(0x20E7CC, ori(v1, v1, LOWORD(val)));

	patchInt(0x20EA1C, lui(v0, HIWORD(val)));
	patchInt(0x20EA24, ori(v0, v0, LOWORD(val)));


	val += 4;
	//field16
	patchInt(0x20E594, lui(v0, HIWORD(val)));
	patchInt(0x20E594 + 4, ori(v0, v0, LOWORD(val)));

	patchInt(0x20E5B8, lui(v0, HIWORD(val)));
	patchInt(0x20E5B8 + 4, ori(v0, v0, LOWORD(val)));

	patchInt(0x20E734, lui(v0, HIWORD(val)));
	patchInt(0x20E738, ori(v0, v0, LOWORD(val)));

	patchInt(0x20EBBC, lui(v0, HIWORD(val)));
	patchInt(0x20EBC4, ori(v0, v0, LOWORD(val)));

	patchInt(0x20EBF0, lui(v0, HIWORD(val)));
	patchInt(0x20EBF8, ori(v0, v0, LOWORD(val)));

	patchInt(0x20EECC, lui(v1, HIWORD(val)));
	patchInt(0x20EED4, ori(v1, v1, LOWORD(val)));

	patchInt(0x20F41C, lui(v0, HIWORD(val)));
	patchInt(0x20F41C + 4, ori(v0, v0, LOWORD(val)));

	patchInt(0x20F94C, lui(v0, HIWORD(val)));
	patchInt(0x20F954, ori(v0, v0, LOWORD(val)));

	patchInt(0x20FA90, lui(v0, HIWORD(val)));
	patchInt(0x20FA98, ori(v0, v0, LOWORD(val)));


	val = (int)&onaga_remap_table[0];
	patchInt(0x2418E4, lui(v0, HIWORD(val)));
	patchInt(0x2418F4, ori(v0, v0, LOWORD(val)));

	val = (int)&attack_region_list[0];
	patchInt(0x19F674, lui(v0, HIWORD(val)));
	patchInt(0x19F684, ori(v0, v0, LOWORD(val)));
}
#ifndef PS2_BUILD
void dump_reactions_table()
{
	int addr = 0x595BD0;

	_printf("DUMPING REACTIONs\n");
	char msgBuffer[1256] = {};

	for (int i = 0; i < TOTAL_REACTIONS; i++)
	{

		reaction_table_entry r = *(reaction_table_entry*)(addr + (sizeof(reaction_table_entry) * i));
		//	sprintf(msgBuffer, "{%d, %d, %d, %d, %x, %d, %d},\n", snd.field0, snd.field4, snd.field8, snd.field12, snd.volume, snd.field20, snd.field24);

		switch (r.type)
		{
		case TYPE_FUNCTION_CALL:
			_printf("{TYPE_FUNCTION_CALL, 0x%X, %d, %d, %d},", r.arg, r.field8, r.field12, r.field16);
			break;
		case TYPE_2:
			_printf("{TYPE_2, %d, %d, %d, %d},", r.arg, r.field8, r.field12, r.field16);
			break;
		case TYPE_SCRIPT_FUNCTION:
			_printf("{TYPE_SCRIPT_FUNCTION, %d, %d, %d, %d},", r.arg, r.field8, r.field12, r.field16);
			break;
		case TYPE_REACTIONS_FUNCTION:
			_printf("{TYPE_REACTIONS_FUNCTION, %d, %d, %d, %d},", r.arg, r.field8, r.field12, r.field16);
			break;
		case TYPE_TRANSFER:
			_printf("{TYPE_TRANSFER, %d, %d, %d, %d},", r.arg, r.field8, r.field12, r.field16);
			break;
		default:
			_printf("{%d, %d, %d, %d, %d},", r.type, r.arg, r.field8, r.field12, r.field16);
			break;
		}
		_printf("#%3d\n", i);


	}
}

void dump_onaga_remap_table()
{
	int addr = 0x598340;

	_printf("DUMPING ONAGA REACTIONs\n");
	char msgBuffer[1256] = {};

	for (int i = 0; i < 314; i++)
	{
		int ent = *(int*)(addr + sizeof(int) * i);

		_printf("%d, ", ent);
		_printf("#%3d\n", i);
	}
}
#endif