#include<stdio.h>
#include<math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
u8 SBox[256] =
{
	0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76,
	0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0,
	0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15,
	0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75,
	0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84,
	0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF,
	0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8,
	0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2,
	0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73,
	0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB,
	0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79,
	0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08,
	0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A,
	0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E,
	0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF,
	0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16
};
double Parity[256] =
{
	0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
	1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,
	1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,
	0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
	1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,
	0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
	0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
	1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0
};
u8 Sigma[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15 };
u32 AesKey1[4] = { 0, 0, 0, 0 };
u32 AesKey2[4] = { 0, 0, 0, 0 };
#define MAKEU32(a, b) (((u32)(a) << 16) | ((u32)(b) ))
#define MAKEU16(a, b) (((u16)(a) << 8) | ((u16)(b) ))
#define ROTL32(word32, offset) ((word32 << offset) | (word32 >> (32 - offset)))
#define SB(index, offset) (((u32)(sb[(index) % 16])) << (offset * 8))
#define MKSTEP3(j)\
w = SB(j * 4 + 0, 3) | SB(j * 4 + 5, 0) | SB(j * 4 + 10, 1) | SB(j * 4 + 15, 2);\
t = ROTL32(w, 16) ^ ((w << 1) & 0xfefefefeUL) ^ (((w >> 7) & 0x01010101UL) * 0x1b);\
R3[j] = AesKey1[j] ^ w ^ t ^ ROTL32(t, 8)
#define MKSTEP2(j)\
w = SB(j * 4 + 0, 3) | SB(j * 4 + 5, 0) | SB(j * 4 + 10, 1) | SB(j * 4 + 15, 2);\
t = ROTL32(w, 16) ^ ((w << 1) & 0xfefefefeUL) ^ (((w >> 7) & 0x01010101UL) * 0x1b);\
R2[j] = AesKey1[j] ^ w ^ t ^ ROTL32(t, 8)

u16 A[16], B[16]; // LFSR
u32 R1[4], R2[4], R3[4]; // FSM
u32 R1tempp[4];
u8 tmpp[16];
u32 w, t;
u8 sb[16];
void aes_enc_round(u32 * result, u32 * state, u32 * roundKey)
{
#define MKSTEP(j)\
w = SB(j * 4 + 0, 3) | SB(j * 4 + 5, 0) | SB(j * 4 + 10, 1) | SB(j * 4 + 15, 2);\
t = ROTL32(w, 16) ^ ((w << 1) & 0xfefefefeUL) ^ (((w >> 7) & 0x01010101UL) * 0x1b);\
result[j] = roundKey[j] ^ w ^ t ^ ROTL32(t, 8)
	u32 w, t;
	u8 sb[16];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			sb[i * 4 + j] = SBox[(state[i] >> (j * 8)) & 0xff];
	MKSTEP(0);
	MKSTEP(1);
	MKSTEP(2);
	MKSTEP(3);
}
u16 mul_x(u16 v, u16 c)
{
	if (v & 0x8000)
		return(v << 1) ^ c;
	else
		return (v << 1);
}
#define mul_xs(v,c) ((v<<1)^(v&0x8000?c:0))
#define mul_x_invs(v,d) ((v >> 1) ^ (v & 1 ? d : 0))
u16 mul_x_inv(u16 v, u16 d)
{
	if (v & 0x0001)
		return(v >> 1) ^ d;
	else
		return (v >> 1);
}
void permute_sigma(u32 * state)
{
	u8 tmp[16];
	for (int i = 0; i < 16; i++)
		tmp[i] = (u8)(state[Sigma[i] >> 2] >> ((Sigma[i] & 3) << 3));
	for (int i = 0; i < 4; i++)
		state[i] = MAKEU32(MAKEU16(tmp[4 * i + 3], tmp[4 * i + 2]),
			MAKEU16(tmp[4 * i + 1], tmp[4 * i]));
}
void fsm_update(void)
{
	u32 R1temp[4];
	memcpy(R1temp, R1, sizeof(R1));
	for (int i = 0; i < 4; i++)
	{
		u32 T2 = MAKEU32(A[2 * i + 1], A[2 * i]);
		R1[i] = (T2 ^ R3[i]) + R2[i];
	}
	permute_sigma(R1);
	aes_enc_round(R3, R2, AesKey2);
	aes_enc_round(R2, R1temp, AesKey1);
}
void lfsr_update(void)
{
	for (int i = 0; i < 8; i++)
	{
		u16 u = mul_x(A[0], 0x990f) ^ A[1] ^ mul_x_inv(A[8], 0xcc87) ^ B[0];
		u16 v = mul_x(B[0], 0xc963) ^ B[3] ^ mul_x_inv(B[8], 0xe4b1) ^ A[0];
		for (int j = 0; j < 15; j++)
		{
			A[j] = A[j + 1];
			B[j] = B[j + 1];
		}
		A[15] = u;
		B[15] = v;
	}
}
void keystream(u8 * z)
{
	for (int i = 0; i < 4; i++)
	{
		u32 T1 = MAKEU32(B[2 * i + 9], B[2 * i + 8]);
		u32 v = (T1 + R1[i]) ^ R2[i];
		z[i * 4 + 0] = (v >> 0) & 0xff;
		z[i * 4 + 1] = (v >> 8) & 0xff;
		z[i * 4 + 2] = (v >> 16) & 0xff;
		z[i * 4 + 3] = (v >> 24) & 0xff;
	}
	fsm_update();
	lfsr_update();
}
void keyiv_setup(u8 * key, u8 * iv, int is_aead_mode)
{
	for (int i = 0; i < 8; i++)
	{
		A[i] = MAKEU16(iv[2 * i + 1], iv[2 * i]);
		A[i + 8] = MAKEU16(key[2 * i + 1], key[2 * i]);
		B[i] = 0x0000;
		B[i + 8] = MAKEU16(key[2 * i + 17], key[2 * i + 16]);
	}
	if (is_aead_mode == 1)
	{
		B[0] = 0x6C41;
		B[1] = 0x7865;
		B[2] = 0x6B45;
		B[3] = 0x2064;
		B[4] = 0x694A;
		B[5] = 0x676E;
		B[6] = 0x6854;
		B[7] = 0x6D6F;
	}
	for (int i = 0; i < 4; i++)
		R1[i] = R2[i] = R3[i] = 0x00000000;
	for (int i = 0; i < 16; i++)
	{
		u8 z[16];
		keystream(z);
		for (int j = 0; j < 8; j++)
			A[j + 8] ^= MAKEU16(z[2 * j + 1], z[2 * j]);
		if (i == 14)
			for (int j = 0; j < 4; j++)
				R1[j] ^= MAKEU32(MAKEU16(key[4 * j + 3], key[4 * j + 2]),
					MAKEU16(key[4 * j + 1], key[4 * j + 0]));
		if (i == 15)
			for (int j = 0; j < 4; j++)
				R1[j] ^= MAKEU32(MAKEU16(key[4 * j + 19], key[4 * j + 18]),
					MAKEU16(key[4 * j + 17], key[4 * j + 16]));
	}
}

void doing()
{
	u8 key[32] = { 0 };
	u8 iv[16] = { 0 };
	u8 z[16];
	long long i, j, k, x;
	u32 T1[3][4];
	u32 T2[3][4];
	u32 R1t[3][4];                               
	u32 R2t[3][4];                               
	u32 R3t[3][4];  
	u32 zt[3][4];
	u32 alpha[4] = { 0,0,0,0xc };
	u32 l[4] = { 0,0,0,0xc };
	u32 c[4] = { 0,0,0,0xc };
	u32 beta[4]= { 0,0,0,0x80 };
	u32 m[4] = { 0,0,0,0x80 };
	u32 gamma[4] = { 0,0,0,0x81ec5a80 };
	u32 h[4] = { 0,0,0,0x81ec5a80 };
	u32 b[4] = { 0,0,0,0x81ec5a80 };
	u32 n[4] = { 0,0,0,0x81ec5a00 };
	u32 a[4] = { 0,0,0,0xc1000000 };
	u32 q[4] = { 0,0,0,0xa0 };

	u32 temp1[4];
	u32 temp2[4];
	u32 parity;

	FILE *fp1 = fopen("f1.txt", "w+");
	FILE *fp2 = fopen("f2.txt", "w+");
	FILE *fp3 = fopen("f3.txt", "w+");
	FILE *fp4 = fopen("f4.txt", "w+");
	FILE *fp5 = fopen("f5.txt", "w+");
	FILE *fp6 = fopen("f6.txt", "w+");


	double f1 = 0;
	double f2 = 0;
	double f3 = 0;
	double f4 = 0;
	double f5 = 0;
	double f6 = 0;

	for (i = 0; i < 4; i++)for (j = 0; j < 3; j++)
	{
		zt[j][i] = 0;
		T1[j][i] = 0;
		T2[j][i] = 0;
		R1t[j][i] = 0;
		R2t[j][i] = 0;
		R3t[j][i] = 0;
	}

	keyiv_setup(key, iv, 0);
	
	for (j = 0; j < (1 << 19); j++)
	{
		for (i = 0; i < (1 << 24); i++)
		{
			for (k = 0; k < 4; k++)
			{
				zt[0][k] = zt[1][k];
				zt[1][k] = zt[2][k];
				T1[0][k] = T1[1][k];
				T1[1][k] = T1[2][k];
				T2[0][k] = T2[1][k];
				T2[1][k] = T2[2][k];
				R1t[0][k] = R1t[1][k];
				R1t[1][k] = R1t[2][k];
				R2t[0][k] = R2t[1][k];
				R2t[1][k] = R2t[2][k];
				R3t[0][k] = R3t[1][k];
				R3t[1][k] = R3t[2][k];
			}
			keystream(z);

			for (k = 0; k < 4; k++)
			{
				T1[2][k] = MAKEU32(B[2 * k + 9], B[2 * k + 8]);
				T2[2][k] = MAKEU32(A[2 * k + 1], A[2 * k]);
				R1t[2][k] = R1[k];
				R2t[2][k] = R2[k];
				R3t[2][k] = R3[k];
				zt[2][k] = (u32)z[4 * k] ^ ((u32)z[4 * k + 1] << 8) ^ ((u32)z[4 * k + 2] << 16) ^ ((u32)z[4 * k + 3] << 24);
			}
			//f1
			temp1[3] = zt[2][3] ^ R2t[2][3];
			temp2[3] = temp1[3] - T1[2][3];
			parity = a[3] & temp2[3] ^ n[3] & T1[2][3] ^ gamma[3] & temp1[3];
			if (Parity[(parity ^ (parity >> 8) ^ (parity >> 16) ^ (parity >> 24)) & 0xff])f1--;
			else f1++;
			//f2
			temp1[3] = R3t[1][3] ^ T2[1][3];
			temp2[3] = temp1[3] + R2t[1][3];
			parity = temp2[3] & a[3] ^ R2t[1][3] & (beta[3] ^ b[3]) ^ temp1[3] & h[3];
			if (Parity[(parity ^ (parity >> 8) ^ (parity >> 16) ^ (parity >> 24)) & 0xff])f2--;
			else f2++;
			//f3: two AES
			parity = h[3] & R3t[1][3] ^ b[3] & R2t[1][3] ^ alpha[3] & R2t[0][3] ^ c[3] & R1t[0][3];
			if (Parity[(parity ^ (parity >> 8) ^ (parity >> 16) ^ (parity >> 24)) & 0xff])f3--;
			else f3++;
			//f4
			temp1[3] = R1t[0][3] + T1[0][3];
			parity = alpha[3] & temp1[3] ^ c[3] & R1t[0][3] ^ l[3] & T1[0][3];
			if (Parity[(parity ^ (parity >> 8) ^ (parity >> 16) ^ (parity >> 24)) & 0xff])f4--;
			else f4++;
			//f5
			parity = gamma[3] & R2t[2][3] ^ q[3] & R1t[1][3];
			if (Parity[(parity ^ (parity >> 8) ^ (parity >> 16) ^ (parity >> 24)) & 0xff])f5--;
			else f5++;
			//f6
			temp1[3] = R1t[1][3] + T1[1][3];
			parity = beta[3] & temp1[3] ^ q[3] & R1t[1][3] ^ m[3] & T1[1][3];
			if (Parity[(parity ^ (parity >> 8) ^ (parity >> 16) ^ (parity >> 24)) & 0xff])f6--;
			else f6++;
		}
		printf("%d, f1 = ",j);
		printf("%f\n", (log2((fabs(f1) / (j + 1)))-24));
		printf("%d, f2 = ", j);
		printf("%f\n", (log2((fabs(f2) / (j + 1))) - 24));
		printf("%d, f3 = ", j);
		printf("%f\n", (log2((fabs(f3) / (j + 1))) - 24));
		printf("%d, f4 = ", j);
		printf("%f\n", (log2((fabs(f4) / (j + 1))) - 24));
		printf("%d, f5 = ", j);
		printf("%f\n", (log2((fabs(f5) / (j + 1))) - 24));
		printf("%d, f6 = ", j);
		printf("%f\n", (log2((fabs(f6) / (j + 1))) - 24));

		fprintf(fp1, "%d, f1 = ", j);
		fprintf(fp1, "%f\n", (log2((fabs(f1) / (j + 1))) - 24));
		fprintf(fp2, "%d, f2 = ", j);
		fprintf(fp2, "%f\n", (log2((fabs(f2) / (j + 1))) - 24));
		fprintf(fp3, "%d, f3 = ", j);
		fprintf(fp3, "%f\n", (log2((fabs(f3) / (j + 1))) - 24));
		fprintf(fp4, "%d, f4 = ", j);
		fprintf(fp4, "%f\n", (log2((fabs(f4) / (j + 1))) - 24));
		fprintf(fp5, "%d, f5 = ", j);
		fprintf(fp5, "%f\n", (log2((fabs(f5) / (j + 1))) - 24));
		fprintf(fp6, "%d, f6 = ", j);
		fprintf(fp6, "%f\n", (log2((fabs(f6) / (j + 1))) - 24));
	}
}

int main()
{
	doing();
}
