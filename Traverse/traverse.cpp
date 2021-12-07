//Keep the search result(snow.txt) in the same folder
#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<math.h>

typedef unsigned __int32 u32;
typedef unsigned __int8 u8;

void Readtxt(u32 alpha[4], u32 beta[4], u32 gamma[4], u32 a[4], u32 b[4], u32 c[4], u32 d[4], u32 e[4], u32 f[4], u32 h[4], u32 x[4], u32 y[4], u32 z[4], u32 t[4], u32 l[4], u32 m[4], u32 n[4], u32 p[4], u32 q[4], u32 u[4], u32 v[4], u32 w[4])
{
	FILE *filename = fopen("snow.txt", "r+");

	struct stat file;
	stat("snow.txt", &file);
	int lenth = file.st_size;
	char *fp = (char*)malloc(lenth);

	size_t sz = fread(fp, 1, (lenth), filename);

	int i, j, k;

	for (i = 0; i < 4; i++)
	{
		alpha[i] = 0;
		beta[i] = 0;
		gamma[i] = 0;
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
		e[i] = 0;
		f[i] = 0;
		h[i] = 0;
		l[i] = 0;
		m[i] = 0;
		n[i] = 0;
		p[i] = 0;
		q[i] = 0;
		x[i] = 0;
		y[i] = 0;
		z[i] = 0;
		t[i] = 0;
		u[i] = 0;
		v[i] = 0;
		w[i] = 0;
	}
	for (i = 0; i < (lenth + 1); i++)
	{
		switch (fp[i])
		{
		case'a':
			if ((fp[i + 1] == 'l') && (fp[i + 2] == 'p') && (fp[i + 3] == 'h') && (fp[i + 4] == 'a') && (fp[i + 5] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 6 + j] >= '0') && (fp[i + 6 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 6 + j] - '0');
					j++;
				}
				alpha[k / 32] ^= (fp[i + 9 + j] - '0') << (k % 32);
			}
			else
			{
				if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
				{
					j = 0; k = 0;
					while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
					{
						k = k * 10 + (fp[i + 2 + j] - '0');
						j++;
					}
					a[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
				}
			}
			break;
		case'b':
			if ((fp[i + 1] == 'e') && (fp[i + 2] == 't') && (fp[i + 3] == 'a') && (fp[i + 4] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 5 + j] >= '0') && (fp[i + 5 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 5 + j] - '0');
					j++;
				}
				beta[k / 32] ^= (fp[i + 8 + j] - '0') << (k % 32);
			}
			else
			{
				if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
				{
					j = 0; k = 0;
					while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
					{
						k = k * 10 + (fp[i + 2 + j] - '0');
						j++;
					}
					b[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
				}
			}
			break;
		case'g':
			if ((fp[i + 1] == 'a') && (fp[i + 2] == 'm') && (fp[i + 3] == 'm') && (fp[i + 4] == 'a') && (fp[i + 5] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 6 + j] >= '0') && (fp[i + 6 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 6 + j] - '0');
					j++;
				}
				gamma[k / 32] ^= (fp[i + 9 + j] - '0') << (k % 32);
			}
			break;
		case'c':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				c[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'd':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				d[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'e':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				e[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'f':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				f[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'h':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				h[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'l':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				l[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'm':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				m[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'n':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				n[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'p':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				p[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'q':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				q[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'x':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				x[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'y':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				y[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'z':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				z[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case't':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				t[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'u':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				u[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'v':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				v[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		case'w':
			if ((fp[i - 1] == '\'') && (fp[i + 1] == '_'))
			{
				j = 0; k = 0;
				while ((fp[i + 2 + j] >= '0') && (fp[i + 2 + j] <= '9'))
				{
					k = k * 10 + (fp[i + 2 + j] - '0');
					j++;
				}
				w[k / 32] ^= (fp[i + 5 + j] - '0') << (k % 32);
			}
			break;
		default:break;
		}
	}
}

void sigma(unsigned __int32 a[4]) 
{
	unsigned __int32 temp1[16];
	unsigned __int32 temp2[16];
	int c[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15 };
	int i;

	for (i = 0; i < 16; i++)temp1[i] = (a[i / 4] >> (8 * (i % 4))) & 0xff;
	for (i = 0; i < 16; i++) temp2[i] = temp1[c[i]];
	for (i = 0; i < 4; i++) a[i] = temp2[4 * i] ^ (temp2[4 * i + 1] << 8) ^ (temp2[4 * i + 2] << 16) ^ (temp2[4 * i + 3] << 24);
}

double Sigma(u32 in[4], u32 out[4])
{
	int i;
	u32 temp[4];

	for (i = 0; i < 4; i++)temp[i] = in[i];
	sigma(temp);
	for (i = 0; i < 4; i++)
	{
		if (temp[i] == out[i])continue;
		else  return 9527;
	}
	return 0;
}

int wt(u32 in)
{
	u32 temp;
	int w = 0;

	temp = in;
	while (temp != 0)
	{
		temp &= temp - 1;
		w++;
	}
	return w;
}

double Mo32jia(u32 in1[4], u32 in2[4], u32 out[4], int sym[2])
{
	int i, j;
	u32 In1[4];
	u32 In2[4];
	int temp;
	int e = 0;
	double cor = 0;

	for (i = 0; i < 4; i++)
	{
		In1[i] = in1[i] ^ out[i];
		In2[i] = in2[i] ^ out[i];
	}

	for (i = 0; i < 4; i++) sym[0] ^= wt(In1[i] & In2[i]) & 1;
	for (j = 0; j < 4; j++)
	{
		e = 0;
		for (i = 31; i >= 0; i--)
		{
			temp = (((out[j] >> i) & 1) << 2) ^ (((In1[j] >> i) & 1) << 1) ^ ((In2[j] >> i) & 1);
			if (e)
			{
				cor++;
				switch (temp)
				{
				case 0:
				case 3:
				case 5:
				case 6:break;
				case 1:
				case 2:
				case 4:
				case 7:e = 0; break;
				}
			}
			else
			{
				switch (temp)
				{
				case 0:break;
				case 4:e = 1; break;
				case 1:
				case 2:
				case 3:
				case 5:
				case 6:
				case 7: return 9527;
				}
			}
		}
	}
	return cor;
}

double Mo16jia(u32 in1[4], u32 in2[4], u32 out[4], u32 mid[4], char Mid[], int sym[2])
{
	int i, j;
	u32 In1[4];
	u32 In2[4];
	int temp;
	int e = 0;
	double cor = 0;

	for (i = 0; i < 4; i++)
	{
		In1[i] = in1[i] ^ out[i];
		In2[i] = in2[i] ^ out[i];
	}

	for (i = 0; i < 4; i++) sym[0] ^= wt(In1[i] & In2[i]) & 1;
	for (j = 7; j >= 0; j--)
	{
		e = 0;
		for (i = 15; i >= 0; i--)
		{
			temp = (((out[j / 2] >> (16 * (j % 2) + i)) & 1) << 2) ^ (((In1[j / 2] >> (16 * (j % 2) + i)) & 1) << 1) ^ (((In2[j / 2] >> (16 * (j % 2) + i)) & 1));
			if (e)
			{
				cor++;
				switch (temp)
				{
				case 0:
				case 3:
				case 5:
				case 6:break;
				case 1:
				case 2:
				case 4:
				case 7:e = 0; break;
				}
			}
			else
			{
				switch (temp)
				{
				case 0:break;
				case 4:e = 1; break;
				case 1:
				case 2:
				case 3:
				case 5:
				case 6:
				case 7:printf("%s layer %d-th addition failed\n", Mid, j); return 0;
				}
			}
		}
	}
	return cor;
}

double Mo8jia(u32 in1[4], u32 in2[4], u32 out[4], u32 mid[4], char Mid[], int sym[2])
{
	int i, j;
	u32 In1[4];
	u32 In2[4];
	int temp;
	int e = 0;
	double cor = 0;

	for (i = 0; i < 4; i++)
	{
		In1[i] = in1[i] ^ out[i];
		In2[i] = in2[i] ^ out[i];
	}

	for (i = 0; i < 4; i++) sym[0] ^= wt(In1[i] & In2[i]) & 1;
	for (j = 15; j >= 0; j--)
	{
		e = 0;
		for (i = 7; i >= 0; i--)
		{
			temp = (((out[j / 4] >> (8 * (j % 4) + i)) & 1) << 2) ^ (((In1[j / 4] >> (8 * (j % 4) + i)) & 1) << 1) ^ (((In2[j / 4] >> (8 * (j % 4) + i)) & 1));
			if (e)
			{
				cor++;
				switch (temp)
				{
				case 0:
				case 3:
				case 5:
				case 6:break;
				case 1:
				case 2:
				case 4:
				case 7:e = 0; break;
				}
			}
			else
			{
				switch (temp)
				{
				case 0:break;
				case 4:e = 1; break;
				case 1:
				case 2:
				case 3:
				case 5:
				case 6:
				case 7:printf("%s layer %d-th addition failed\n", Mid, j); return 0;
				}
			}
		}
	}
	return cor;
}

void aes_p(u32 state[4])
{
	u32 result[4];
#define ROTL32(word32, offset) ((word32 << offset) | (word32 >> (32 - offset)))
#define SB(index, offset) (((u32)(sb[(index) % 16])) << (offset * 8))
#define MKSTEP(j)\
w = SB(j * 4 + 0, 3) | SB(j * 4 + 5, 0) | SB(j * 4 + 10, 1) | SB(j * 4 + 15, 2);\
t = ROTL32(w, 16) ^ ((w << 1) & 0xfefefefeUL) ^ (((w >> 7) & 0x01010101UL) * 0x1b);\
result[j] = w ^ t ^ ROTL32(t, 8)
	u32 w, t;
	u8 sb[16];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			sb[i * 4 + j] = (state[i] >> (j * 8)) & 0xff;
	MKSTEP(0);
	MKSTEP(1);
	MKSTEP(2);
	MKSTEP(3);
	for (int k = 0; k < 4; k++) state[k] = result[k];
}

int Parity(u32 state[4])
{
	int i;
	u32 temp = 0;
	for (i = 0; i < 4; i++)
	{
		temp ^= state[i];
	}
	temp = ((temp >> 16) ^ temp) & 0xffff;
	temp = ((temp >> 8) ^ temp) & 0xff;
	temp = ((temp >> 4) ^ temp) & 0xf;
	temp = ((temp >> 2) ^ temp) & 0x3;
	temp = ((temp >> 1) ^ temp) & 1;
	return temp;
}

double AES_P(u32 in[4], u32 out[4], char Ch[])
{
	int i, j;
	u32 e[4];
	u32 temp[4];

	for (i = 0; i < 128; i++)
	{
		e[i / 32] = 1 << (i % 32);
		e[((i / 32) + 1) & 3] = 0;
		e[((i / 32) + 2) & 3] = 0;
		e[((i / 32) + 3) & 3] = 0;
		aes_p(e);
		for (j = 0; j < 4; j++)
		{
			temp[j] = out[j] & e[j];
		}
		if (Parity(temp) ^ ((in[i / 32] >> (i % 32)) & 1))
		{
			return 9527;
		}
		else
		{
			continue;
		}
	}
	return 0;
}

void pu(u8 S[256], int pu[256][256])
{
	int x, a, b, i, max;
	int wt[256];

	for (x = 0; x<256; x++) 
	{
		wt[x] = 0;
		for (i = 0; i<8; i++) wt[x] ^= (x >> i) & 1;
		if (wt[x])	wt[x] = -1;
		else wt[x] = 1;
	}

	for (a = 0; a<256; a++) 
	{
		for (b = 0; b<256; b++)	
		{
			pu[a][b] = 0;
			for (x = 0; x<256; x++)
				pu[a][b] += wt[(b&S[x]) ^ (a&x)];
		}
	}
	max = 0;
	for (a = 1; a<256; a++)
	{
		for (b = 1; b<256; b++)
		{
			if (pu[a][b]>max) max = pu[a][b];
			else if (-pu[a][b]>max) max = -pu[a][b];
		}
	}
}

double AES_S(u32 in[4], u32 out[4], int pu[256][256], char Ch[], int sym[2])
{
	int i;
	int temp[16];
	double cor = 0;
	for (i = 0; i < 16; i++)
	{
		temp[i] = pu[(in[i / 4] >> (8 * (i & 3))) & 0xff][(out[i / 4] >> (8 * (i & 3))) & 0xff];
		if (temp[i] < 0) sym[0] ^= 1;
		if (temp != 0)
		{
			cor += log2((double)(256 / fabs(temp[i])));
		}
		else
		{
			return 9527;
		}
	}
	return cor;
}

void doing()
{
	FILE *fp = fopen("traverse_abcdq.txt", "w");

	u32 alpha[4];
	u32 beta[4];
	u32 gamma[4];
	u32 a[4];
	u32 b[4];
	u32 c[4];
	u32 d[4];
	u32 e[4];
	u32 f[4];
	u32 h[4];
	u32 u[4];
	u32 v[4];
	u32 w[4];
	u32 l[4];
	u32 m[4];
	u32 n[4];
	u32 p[4];
	u32 q[4];
	u32 x[4];
	u32 y[4];
	u32 z[4];
	u32 t[4];
	u32 g1[4];
	u32 g2[4];
	u32 g3[4];
	u32 g4[4];
	u32 g5[4];

	u8 S[256] = {
		0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
		0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
		0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
		0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
		0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
		0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
		0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
		0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
		0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
		0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
		0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
		0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
		0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
		0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
		0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
		0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
	};
	int result[256][256];
	double tc = 0;
	int sym[2] = { 0,0 };
	u32 i, j, k, r, x1, y1;

	char Ach[] = "A";
	char Bch[] = "B";
	char Cch[] = "C";
	char xch[] = "x";
	char ych[] = "y";
	char zch[] = "z";
	char tch[] = "t";
	char pch[] = "p";
	char vch[] = "v";
	char wch[] = "w";

	pu(S, result);

	Readtxt(alpha, beta, gamma, a, b, c, d, e, f, h, x, y, z, t, l, m, n, p, q, u, v, w);

	printf("alpha: %x %x %x %x\n", alpha[3], alpha[2], alpha[1], alpha[0]);
	printf("beta: %x %x %x %x\n", beta[3], beta[2], beta[1], beta[0]);
	printf("gamma: %x %x %x %x\n", gamma[3], gamma[2], gamma[1], gamma[0]);
	printf("a: %x %x %x %x\n", a[3], a[2], a[1], a[0]);
	printf("b: %x %x %x %x\n", b[3], b[2], b[1], b[0]);
	printf("c: %x %x %x %x\n", c[3], c[2], c[1], c[0]);
	printf("d: %x %x %x %x\n", d[3], d[2], d[1], d[0]);
	printf("e: %x %x %x %x\n", e[3], e[2], e[1], e[0]);
	printf("f: %x %x %x %x\n", f[3], f[2], f[1], f[0]);
	printf("u: %x %x %x %x\n", u[3], u[2], u[1], u[0]);
	printf("v: %x %x %x %x\n", v[3], v[2], v[1], v[0]);
	printf("w: %x %x %x %x\n", w[3], w[2], w[1], w[0]);
	printf("p: %x %x %x %x\n", p[3], p[2], p[1], p[0]);
	printf("q: %x %x %x %x\n", q[3], q[2], q[1], q[0]);
	printf("x: %x %x %x %x\n", x[3], x[2], x[1], x[0]);
	printf("y: %x %x %x %x\n", y[3], y[2], y[1], y[0]);
	printf("z: %x %x %x %x\n", z[3], z[2], z[1], z[0]);
	printf("t: %x %x %x %x\n", t[3], t[2], t[1], t[0]);
	printf("l: %x %x %x %x\n", l[3], l[2], l[1], l[0]);
	printf("m: %x %x %x %x\n", m[3], m[2], m[1], m[0]);
	printf("n: %x %x %x %x\n", n[3], n[2], n[1], n[0]);
	printf("h: %x %x %x %x\n", h[3], h[2], h[1], h[0]);


	for (i = 0; i<4; i++)
	{
		g1[i] = e[i] ^ l[i];
		g2[i] = f[i] ^ m[i];
		g3[i] = n[i] ^ d[i];
		g4[i] = b[i] ^ beta[i];
		g5[i] = d[i] ^ h[i];
	}
	printf("g1: %x %x %x %x\n", g1[3], g1[2], g1[1], g1[0]);
	printf("g2: %x %x %x %x\n", g2[3], g2[2], g2[1], g2[0]);
	printf("g3: %x %x %x %x\n", g3[3], g3[2], g3[1], g3[0]);
	printf("g4: %x %x %x %x\n", g4[3], g4[2], g4[1], g4[0]);
	printf("g5: %x %x %x %x\n", g5[3], g5[2], g5[1], g5[0]);



	tc += AES_P(p, gamma, pch);
	tc += AES_P(v, g5, vch);
	tc += AES_P(w, b, wch);
	tc += Sigma(u, a);
	tc += Mo32jia(a, g3, gamma, sym);
	tc += Mo32jia(g4, g5, u, sym);
	tc += Mo32jia(e, c, alpha, sym);
	tc += Mo32jia(f, q, beta, sym);
	tc += AES_S(alpha, v, result, Ach, sym);
	tc += AES_S(c, w, result, Bch, sym);
	tc += AES_S(q, p, result, Cch, sym);

	printf("total correlation: %f,sign: %d\n", tc, sym[0]);

	//keep other parameters unchanged, traverse a,b,c,d,q

	double atemp = 0;
	double ctemp = 0;
	double qtemp = 0;
	double total = 0;
	int sym1[4][2] = { 0 };
	u32 bw[256] = {
		0x00000000, 0x2161a1e0, 0x62a2e321, 0x43c342c1, 0xc445c643, 0xe52467a3, 0xa6e72562, 0x87868482, 0xa9eb2d67, 0x888a8c87, 0xcb49ce46, 0xea286fa6, 0x6daeeb24, 0x4ccf4ac4, 0x0f0c0805, 0x2e6da9e5,
		0x72b6fa2e, 0x53d75bce, 0x1014190f, 0x3175b8ef, 0xb6f33c6d, 0x97929d8d, 0xd451df4c, 0xf5307eac, 0xdb5dd749, 0xfa3c76a9, 0xb9ff3468, 0x989e9588, 0x1f18110a, 0x3e79b0ea, 0x7dbaf22b, 0x5cdb53cb,
		0xe46cf45c, 0xc50d55bc, 0x86ce177d, 0xa7afb69d, 0x2029321f, 0x014893ff, 0x428bd13e, 0x63ea70de, 0x4d87d93b, 0x6ce678db, 0x2f253a1a, 0x0e449bfa, 0x89c21f78, 0xa8a3be98, 0xeb60fc59, 0xca015db9,
		0x96da0e72, 0xb7bbaf92, 0xf478ed53, 0xd5194cb3, 0x529fc831, 0x73fe69d1, 0x303d2b10, 0x115c8af0, 0x3f312315, 0x1e5082f5, 0x5d93c034, 0x7cf261d4, 0xfb74e556, 0xda1544b6, 0x99d60677, 0xb8b7a797,
		0xc8d8e8b8, 0xe9b94958, 0xaa7a0b99, 0x8b1baa79, 0x0c9d2efb, 0x2dfc8f1b, 0x6e3fcdda, 0x4f5e6c3a, 0x6133c5df, 0x4052643f, 0x039126fe, 0x22f0871e, 0xa576039c, 0x8417a27c, 0xc7d4e0bd, 0xe6b5415d,
		0xba6e1296, 0x9b0fb376, 0xd8ccf1b7, 0xf9ad5057, 0x7e2bd4d5, 0x5f4a7535, 0x1c8937f4, 0x3de89614, 0x13853ff1, 0x32e49e11, 0x7127dcd0, 0x50467d30, 0xd7c0f9b2, 0xf6a15852, 0xb5621a93, 0x9403bb73,
		0x2cb41ce4, 0x0dd5bd04, 0x4e16ffc5, 0x6f775e25, 0xe8f1daa7, 0xc9907b47, 0x8a533986, 0xab329866, 0x855f3183, 0xa43e9063, 0xe7fdd2a2, 0xc69c7342, 0x411af7c0, 0x607b5620, 0x23b814e1, 0x02d9b501,
		0x5e02e6ca, 0x7f63472a, 0x3ca005eb, 0x1dc1a40b, 0x9a472089, 0xbb268169, 0xf8e5c3a8, 0xd9846248, 0xf7e9cbad, 0xd6886a4d, 0x954b288c, 0xb42a896c, 0x33ac0dee, 0x12cdac0e, 0x510eeecf, 0x706f4f2f,
		0x90b0d070, 0xb1d17190, 0xf2123351, 0xd37392b1, 0x54f51633, 0x7594b7d3, 0x3657f512, 0x173654f2, 0x395bfd17, 0x183a5cf7, 0x5bf91e36, 0x7a98bfd6, 0xfd1e3b54, 0xdc7f9ab4, 0x9fbcd875, 0xbedd7995,
		0xe2062a5e, 0xc3678bbe, 0x80a4c97f, 0xa1c5689f, 0x2643ec1d, 0x07224dfd, 0x44e10f3c, 0x6580aedc, 0x4bed0739, 0x6a8ca6d9, 0x294fe418, 0x082e45f8, 0x8fa8c17a, 0xaec9609a, 0xed0a225b, 0xcc6b83bb,
		0x74dc242c, 0x55bd85cc, 0x167ec70d, 0x371f66ed, 0xb099e26f, 0x91f8438f, 0xd23b014e, 0xf35aa0ae, 0xdd37094b, 0xfc56a8ab, 0xbf95ea6a, 0x9ef44b8a, 0x1972cf08, 0x38136ee8, 0x7bd02c29, 0x5ab18dc9,
		0x066ade02, 0x270b7fe2, 0x64c83d23, 0x45a99cc3, 0xc22f1841, 0xe34eb9a1, 0xa08dfb60, 0x81ec5a80, 0xaf81f365, 0x8ee05285, 0xcd231044, 0xec42b1a4, 0x6bc43526, 0x4aa594c6, 0x0966d607, 0x280777e7,
		0x586838c8, 0x79099928, 0x3acadbe9, 0x1bab7a09, 0x9c2dfe8b, 0xbd4c5f6b, 0xfe8f1daa, 0xdfeebc4a, 0xf18315af, 0xd0e2b44f, 0x9321f68e, 0xb240576e, 0x35c6d3ec, 0x14a7720c, 0x576430cd, 0x7605912d,
		0x2adec2e6, 0x0bbf6306, 0x487c21c7, 0x691d8027, 0xee9b04a5, 0xcffaa545, 0x8c39e784, 0xad584664, 0x8335ef81, 0xa2544e61, 0xe1970ca0, 0xc0f6ad40, 0x477029c2, 0x66118822, 0x25d2cae3, 0x04b36b03,
		0xbc04cc94, 0x9d656d74, 0xdea62fb5, 0xffc78e55, 0x78410ad7, 0x5920ab37, 0x1ae3e9f6, 0x3b824816, 0x15efe1f3, 0x348e4013, 0x774d02d2, 0x562ca332, 0xd1aa27b0, 0xf0cb8650, 0xb308c491, 0x92696571,
		0xceb236ba, 0xefd3975a, 0xac10d59b, 0x8d71747b, 0x0af7f0f9, 0x2b965119, 0x685513d8, 0x4934b238, 0x67591bdd, 0x4638ba3d, 0x05fbf8fc, 0x249a591c, 0xa31cdd9e, 0x827d7c7e, 0xc1be3ebf, 0xe0df9f5f,
	};
	
	// one linear hull

	total = 0;        
	for (r = 1; r < 256; r++)
	{
		if (((bw[r] >> 31) & 1) ^ 1)continue;
		w[3] = r;
		b[3] = bw[r];
		for (i = 1; i < 256; i++)
		{
			sym1[0][0] = 0;
			atemp = 0;
			a[3] = i << 24;
			g4[3] = b[3] ^ beta[3];
			atemp += Mo32jia(a, g3, gamma, sym1[0]);
			if (atemp > 9000)continue;
			u[3] = a[3];
			sigma(u);
			atemp += Mo32jia(g4, g5, u, sym1[0]);
			if (atemp > 9000)continue;
			for (j = 1; j < 256; j++)
			{
				qtemp = atemp;
				sym1[1][0] = sym1[0][0];
				q[3] = j;
				qtemp += Mo32jia(f, q, beta, sym1[1]);
				if (qtemp > 9000)continue;
				qtemp += AES_S(q, p, result, Cch, sym1[1]);
				if (qtemp > 9000)continue;
				for (k = 1; k < 256; k++)
				{
					ctemp = qtemp;
					sym1[2][0] = sym1[1][0];
					c[3] = k;
					ctemp += Mo32jia(e, c, alpha, sym1[2]);
					if (ctemp > 9000)continue;
					ctemp += AES_S(c, w, result, Bch, sym1[2]);
					if (ctemp > 9000)continue;
					ctemp += AES_S(alpha, v, result, Ach, sym1[2]);
					ctemp += AES_P(p, gamma, pch);
					ctemp += AES_P(v, g5, vch);
					if (ctemp > 9000)continue;
					fprintf(fp, "a[3] = %08x, b[3] = %08x, c[3] = %02x, q[3] = %02x, correlation: %f, sign: %d\n", a[3], b[3], c[3], q[3], ctemp, sym1[2][0]);
					total += pow(2, (44 - ctemp))*pow((-1), sym1[2][0]);
				}
			}
		}


	}
	if (total > 0)sym[1] = 1;
	else
	{
		sym[1] = -1;
		total = (-1)*total;
	}
	total = log2(total) - 44;
	printf("total correlation: %f, ", total);
	fprintf(fp, "total correlation: %f, ", total);
	printf("sign: %d\n", sym[1]);
	fprintf(fp, "sign: %d\n", sym[1]);
	
	// traverse X&Y
	
	FILE *fp1 = fopen("traverse_XY.txt", "w+");
	for (x1 = 1; x1 < 256; x1++)
	{
		alpha[3] = x1;
		l[3] = x1;
		printf("%02x\n", x1);
		for (y1 = 1; y1 < 256; y1++)
		{
			beta[3] = y1;
			m[3] = y1;
			total = 0;
			for (r = 1; r < 256; r++)
			{
				if (((bw[r] >> 31) & 1) ^ 1)continue;
				w[3] = r;
				b[3] = bw[r];
				for (i = 1; i < 256; i++)
				{
					sym1[0][0] = 0;
					atemp = 0;
					a[3] = i << 24;
					g4[3] = b[3] ^ beta[3];
					atemp += Mo32jia(a, g3, gamma, sym1[0]);
					if (atemp > 9000)continue;
					u[3] = a[3];
					sigma(u);
					atemp += Mo32jia(g4, g5, u, sym1[0]);
					if (atemp > 9000)continue;
					for (j = 1; j < 256; j++)
					{
						qtemp = atemp;
						sym1[1][0] = sym1[0][0];
						q[3] = j;
						qtemp += Mo32jia(m, q, beta, sym1[1]);
						if (qtemp > 9000)continue;
						qtemp += AES_S(q, p, result, Cch, sym1[1]);
						if (qtemp > 9000)continue;
						for (k = 1; k < 256; k++)
						{
							ctemp = qtemp;
							sym1[2][0] = sym1[1][0];
							c[3] = k;
							ctemp += Mo32jia(l, c, alpha, sym1[2]);
							if (ctemp > 9000)continue;
							ctemp += AES_S(c, w, result, Bch, sym1[2]);
							if (ctemp > 9000)continue;
							ctemp += AES_S(alpha, v, result, Ach, sym1[2]);
							ctemp += AES_P(p, gamma, pch);
							ctemp += AES_P(v, g5, vch);
							if (ctemp > 9000)continue;
							total += pow(2, (44 - ctemp))*pow((-1), sym1[2][0]);
						}
					}
				}


			}
			if (total > 0)sym[1] = 1;
			else
			{
				sym[1] = -1;
				total = (-1)*total;
			}
			if (total == 0)continue;
			else
			{
				total = log2(total) - 44;
				printf("alpha= %02x, ", x1);
				fprintf(fp1, "alpha= %02x, ", x1);
				printf("beta= %02x, ", y1);
				fprintf(fp1, "beta= %02x, ", y1);
				printf("total correlation: %f, ", total);
				fprintf(fp1, "total correlation: %f, ", total);
				printf("sign: %d\n", sym[1]);
				fprintf(fp1, "sign: %d\n", sym[1]);
			}
		}
	}
		
}

int main()
{
	doing();
}
