#include <stdio.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<math.h>

typedef unsigned __int8 u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;

void Model(FILE *fp)        //import，变量声明巴拉巴拉
{
	int i, j;
	fprintf(fp, "import stp\n");
	fprintf(fp, "s = stp.Solver()\n");
	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "alpha_%d = s.bitvec('alpha_%d', 1)\n", i, i);
		fprintf(fp, "beta_%d = s.bitvec('beta_%d', 1)\n", i, i);
		fprintf(fp, "gamma_%d = s.bitvec('gamma_%d', 1)\n", i, i);
		fprintf(fp, "a_%d = s.bitvec('a_%d', 1)\n", i, i);
		fprintf(fp, "b_%d = s.bitvec('b_%d', 1)\n", i, i);
		fprintf(fp, "c_%d = s.bitvec('c_%d', 1)\n", i, i);
		fprintf(fp, "d_%d = s.bitvec('d_%d', 1)\n", i, i);
		fprintf(fp, "e_%d = s.bitvec('e_%d', 1)\n", i, i);
		fprintf(fp, "f_%d = s.bitvec('f_%d', 1)\n", i, i);
		fprintf(fp, "l_%d = s.bitvec('l_%d', 1)\n", i, i);
		fprintf(fp, "m_%d = s.bitvec('m_%d', 1)\n", i, i);
		fprintf(fp, "n_%d = s.bitvec('n_%d', 1)\n", i, i);
		fprintf(fp, "u_%d = s.bitvec('u_%d', 1)\n", i, i);
		fprintf(fp, "v_%d = s.bitvec('v_%d', 1)\n", i, i);
		fprintf(fp, "w_%d = s.bitvec('w_%d', 1)\n", i, i);
		fprintf(fp, "x_%d = s.bitvec('x_%d', 1)\n", i, i);
		fprintf(fp, "y_%d = s.bitvec('y_%d', 1)\n", i, i);
		fprintf(fp, "z_%d = s.bitvec('z_%d', 1)\n", i, i);
		fprintf(fp, "t_%d = s.bitvec('t_%d', 1)\n", i, i);
		fprintf(fp, "p_%d = s.bitvec('p_%d', 1)\n", i, i);
		fprintf(fp, "q_%d = s.bitvec('q_%d', 1)\n", i, i);
		fprintf(fp, "X_%d = s.bitvec('X_%d', 32)\n", i, i);
		fprintf(fp, "Y_%d = s.bitvec('Y_%d', 32)\n", i, i);
		fprintf(fp, "Z_%d = s.bitvec('Z_%d', 32)\n", i, i);
		fprintf(fp, "T_%d = s.bitvec('T_%d', 32)\n", i, i);
		fprintf(fp, "g1_%d = s.bitvec('g1_%d', 1)\n", i, i);
		fprintf(fp, "g2_%d = s.bitvec('g2_%d', 1)\n", i, i);
		fprintf(fp, "g3_%d = s.bitvec('g3_%d', 1)\n", i, i);
		fprintf(fp, "g4_%d = s.bitvec('g4_%d', 1)\n", i, i);
		fprintf(fp, "g5_%d = s.bitvec('g5_%d', 1)\n", i, i);
		fprintf(fp, "h_%d = s.bitvec('h_%d', 1)\n", i, i);
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 16; j++)
		{
			fprintf(fp, "A_%d_%d = s.bitvec('A_%d_%d', 1)\n", (4 * (i + 1)), j, (4 * (i + 1)), j);
			fprintf(fp, "A1_%d_%d = s.bitvec('A1_%d_%d', 32)\n", (4 * (i + 1)), j, (4 * (i + 1)), j);
			fprintf(fp, "B_%d_%d = s.bitvec('B_%d_%d', 1)\n", (4 * (i + 1)), j, (4 * (i + 1)), j);
			fprintf(fp, "B1_%d_%d = s.bitvec('B1_%d_%d', 32)\n", (4 * (i + 1)), j, (4 * (i + 1)), j);
			fprintf(fp, "C_%d_%d = s.bitvec('C_%d_%d', 1)\n", (4 * (i + 1)), j, (4 * (i + 1)), j);
			fprintf(fp, "C1_%d_%d = s.bitvec('C1_%d_%d', 32)\n", (4 * (i + 1)), j, (4 * (i + 1)), j);
		}
		fprintf(fp, "S1_%d = s.bitvec('S1_%d', 32)\n", (4 * (i + 1)), (4 * (i + 1)));
		fprintf(fp, "S2_%d = s.bitvec('S2_%d', 32)\n", (4 * (i + 1)), (4 * (i + 1)));
		fprintf(fp, "S3_%d = s.bitvec('S3_%d', 32)\n", (4 * (i + 1)), (4 * (i + 1)));
	}
	for (i = 0; i < 16; i++)
	{
		fprintf(fp, "AA_%d = s.bitvec('AA_%d', 1)\n", i, i);
		fprintf(fp, "BB_%d = s.bitvec('BB_%d', 1)\n", i, i);
		fprintf(fp, "CC_%d = s.bitvec('CC_%d', 1)\n", i, i);
	}
	fprintf(fp, "S1 = s.bitvec('S1', 32)\n");
	fprintf(fp, "S2 = s.bitvec('S2', 32)\n");
	fprintf(fp, "S3 = s.bitvec('S3', 32)\n");
	fprintf(fp, "M1 = s.bitvec('M1', 32)\n");
	fprintf(fp, "M2 = s.bitvec('M2', 32)\n");
	fprintf(fp, "M3 = s.bitvec('M3', 32)\n");
	fprintf(fp, "M4 = s.bitvec('M4', 32)\n");
	fprintf(fp, "Total = s.bitvec('Total', 32)\n");
}

void Nonzero(FILE *fp)      //非平凡条件
{
	int i;

	fprintf(fp, "s.add(");
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "alpha_%d | beta_%d | gamma_%d | ", i, i, i);
	}
	fprintf(fp, "alpha_127 | beta_127 | gamma_127 == 1)\n");
}

void LFSR(FILE *fp)
{
	FILE *c = fopen("LFSR.txt", "r+");

	struct stat a;
	stat("LFSR.txt", &a);
	int lenth = a.st_size;
	char *p = (char*)malloc(lenth);

	size_t sz = fread(p, 1, (lenth), c);

	int i = 0;
	while (p[i] != ';')
	{
		fprintf(fp, "%c", p[i]);
		i++;
	}
}

void Mo32jia(FILE *fp, char in1[], char in2[], char out[], char mid[], char Mid[], char sum[])        //模32加
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		fprintf(fp, "s.add(%s_%d == 0)\n", mid, (31 + 32 * i));
		for (j = 30; j >= 0; j--)
		{
			fprintf(fp, "s.add(%s_%d == %s_%d ^ %s_%d ^ %s_%d ^ %s_%d)\n", mid, (j + 32 * i), mid, (j + 1 + 32 * i), in1, (j + 1 + 32 * i), in2, (j + 1 + 32 * i), out, (j + 1 + 32 * i));
		}
	}

	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(%s_%d >= %s_%d ^ %s_%d)\n", mid, i, out, i, in1, i);
		fprintf(fp, "s.add(%s_%d >= %s_%d ^ %s_%d)\n", mid, i, out, i, in2, i);
	}

	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(s.ite(%s_%d == 0, %s_%d == 0, %s_%d == 10000))\n", mid, i, Mid, i, Mid, i);
	}

	fprintf(fp, "s.add(%s == ", sum);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "%s_%d + ", Mid, i);
	}
	fprintf(fp, "%s_127)\n", Mid);
}

void Mo8jia(FILE *fp, char in1[], char in2[], char out[], char mid[], char Mid[], char sum[])        //模8加
{
	int i, j;

	for (i = 0; i < 16; i++)
	{
		fprintf(fp, "s.add(%s_%d == 0)\n", mid, (7 + 8 * i));
		for (j = 6; j >= 0; j--)
		{
			fprintf(fp, "s.add(%s_%d == %s_%d ^ %s_%d ^ %s_%d ^ %s_%d)\n", mid, (j + 8 * i), mid, (j + 1 + 8 * i), in1, (j + 1 + 8 * i), in2, (j + 1 + 8 * i), out, (j + 1 + 8 * i));
		}
	}

	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(%s_%d >= %s_%d ^ %s_%d)\n", mid, i, out, i, in1, i);
		fprintf(fp, "s.add(%s_%d >= %s_%d ^ %s_%d)\n", mid, i, out, i, in2, i);
	}

	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(s.ite(%s_%d == 0, %s_%d == 0, %s_%d == 1))\n", mid, i, Mid, i, Mid, i);
	}

	fprintf(fp, "s.add(%s == ", sum);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "%s_%d + ", Mid, i);
	}
	fprintf(fp, "%s_127)\n", Mid);
}

void sigma(unsigned __int8 a[16])    //sigma变换
{
	unsigned __int8 temp[16];
	int c[16] = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15 };
	int i;

	for (i = 0; i < 16; i++) temp[i] = a[c[i]];
	for (i = 0; i < 16; i++) a[i] = temp[i];
}

void Sigma(FILE *fp)                     //sigma变换表达式
{
	int i, j;
	unsigned __int8 a[16];

	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(");
		for (j = 0; j < 16; j++)
		{
			a[j] = 0;
		}
		a[i / 8] = 1 << (i % 8);

		sigma(a);

		for (j = 0; j < 128; j++)
		{
			if ((a[j / 8] >> (j % 8)) & 1)
			{
				fprintf(fp, "a_%d ^ ", j);
			}
		}
		fprintf(fp, "u_%d == 0)\n", i);
	}
}

void Identity(FILE *fp)
{
	int i;

	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(a_%d == u_%d)\n", i, i);
	}
}

void exchange(FILE *fp, char in1[], char in2[], char out[])
{
	int i;
	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(%s_%d == %s_%d ^ %s_%d)\n", out, i, in1, i, in2, i);
	}
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

void AES_P(FILE *fp, char in[], char out[])
{
	int i, j;
	u32 a[4];

	for (i = 0; i < 128; i++)
	{
		for (j = 0; j < 4; j++)
		{
			a[j] = 0;
		}
		a[i / 32] = 1 << (i % 32);

		aes_p(a);

		fprintf(fp, "s.add(");
		for (j = 0; j < 128; j++)
		{
			if ((a[j / 32] >> (j % 32)) & 1)
			{
				fprintf(fp, "%s_%d ^ ", out, j);
			}
		}
		fprintf(fp, "%s_%d == 0)\n", in, i);
	}
}

void SboxExprR(FILE *fp, char in[], char out[], char ch[], char Ch[], char sum[], int cor)
{
	char buffer[20];
	int filename;
	filename = sprintf(buffer, "sboxR%d.txt", cor);

	FILE *c = fopen(buffer, "r+");

	struct stat a;
	stat(buffer, &a);
	int lenth = a.st_size;
	char *p = (char*)malloc(lenth + 1);

	size_t sz = fread(p, 1, (lenth + 1), c);

	int i, j;

	for (i = 0; i < 16; i++)
	{
		j = 0;
		while (p[j] != ';')
		{
			switch (p[j])
			{
			case'(':fprintf(fp, "s.add(s.or_(s.not_(s.and_("); break;
			case')':fprintf(fp, ")), %s_%d_%d == 0))\n", ch, cor, i); break;
			case'+':fprintf(fp, ", "); break;
			case'i':
				if (p[j + 3] == '\'')
				{
					fprintf(fp, "%s_%d == 1", in, (8 * i + (p[j + 2] - '0')));
				}
				else
				{
					fprintf(fp, "%s_%d == 0", in, (8 * i + (p[j + 2] - '0')));
				}
				break;
			case'o':
				if (p[j + 4] == '\'')
				{
					fprintf(fp, "%s_%d == 1", out, (8 * i + (p[j + 3] - '0')));
				}
				else
				{
					fprintf(fp, "%s_%d == 0", out, (8 * i + (p[j + 3] - '0')));
				}
				break;
			case'n':
			case'u':
			case't':
			case'0':
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case' ':
			case'\'':break;
			default:printf("error:%c", p[j]); break;
			}
			j++;
		}
		fprintf(fp, "s.add(s.ite(%s_%d_%d == 0, %s_%d_%d == 0, %s_%d_%d == %d))\n", ch, cor, i, Ch, cor, i, Ch, cor, i, ((int)(10000 * (log2(256 / (double)(cor))))));
	}
	fprintf(fp, "s.add(%s_%d == ", sum, cor);
	for (i = 0; i < 15; i++)
	{
		fprintf(fp, "%s_%d_%d + ", Ch, cor, i);
	}
	fprintf(fp, "%s_%d_15)\n", Ch, cor);
}

void SboxR(FILE *fp, char in[], char out[], char ch[], char Ch[], char sum[])
{
	int i;
	for (i = 0; i < 8; i++)
	{
		SboxExprR(fp, in, out, ch, Ch, sum, (4 * (i + 1)));
	}
	for (i = 0; i < 16; i++)
	{
		fprintf(fp, "s.add(%s%s_%d == (%s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d))\n", ch, ch, i, in, (8 * i), in, (8 * i + 1), in, (8 * i + 2), in, (8 * i + 3), in, (8 * i + 4), in, (8 * i + 5), in, (8 * i + 6), in, (8 * i + 7), out, (8 * i), out, (8 * i + 1), out, (8 * i + 2), out, (8 * i + 3), out, (8 * i + 4), out, (8 * i + 5), out, (8 * i + 6), out, (8 * i + 7));
		fprintf(fp, "s.add(%s%s_%d == (%s_4_%d | %s_8_%d | %s_12_%d | %s_16_%d | %s_20_%d | %s_24_%d | %s_28_%d | %s_32_%d))\n", ch, ch, i, ch, i, ch, i, ch, i, ch, i, ch, i, ch, i, ch, i, ch, i);
	}
	fprintf(fp, "s.add(%s == %s_4 + %s_8 + %s_12 + %s_16 + %s_20 + %s_24 + %s_28 + %s_32)\n", sum, sum, sum, sum, sum, sum, sum, sum, sum);
}

void Sboxs(FILE *fp, char in[], char out[], char ch[], char Ch[], char sum[])
{

	FILE *c = fopen("sbox.txt", "r+");

	struct stat a;
	stat("sbox.txt", &a);
	int lenth = a.st_size;
	char *p = (char*)malloc(lenth + 1);

	size_t sz = fread(p, 1, (lenth + 1), c);

	int i, j;

	for (i = 0; i < 16; i++)
	{
		fprintf(fp, "s.add(%s_%d == (%s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d | %s_%d))\n", ch, i, in, (8 * i), in, (8 * i + 1), in, (8 * i + 2), in, (8 * i + 3), in, (8 * i + 4), in, (8 * i + 5), in, (8 * i + 6), in, (8 * i + 7), out, (8 * i), out, (8 * i + 1), out, (8 * i + 2), out, (8 * i + 3), out, (8 * i + 4), out, (8 * i + 5), out, (8 * i + 6), out, (8 * i + 7));
		j = 0;
		while (p[j] != ';')
		{
			switch (p[j])
			{
			case'(':fprintf(fp, "s.add(s.or_(s.not_(s.and_("); break;
			case')':fprintf(fp, ")), %s_%d == 0))\n", ch, i); break;
			case'+':fprintf(fp, ", "); break;
			case'i':
				if (p[j + 3] == '\'')
				{
					fprintf(fp, "%s_%d == 1", in, (8 * i + (p[j + 2] - '0')));
				}
				else
				{
					fprintf(fp, "%s_%d == 0", in, (8 * i + (p[j + 2] - '0')));
				}
				break;
			case'o':
				if (p[j + 4] == '\'')
				{
					fprintf(fp, "%s_%d == 1", out, (8 * i + (p[j + 3] - '0')));
				}
				else
				{
					fprintf(fp, "%s_%d == 0", out, (8 * i + (p[j + 3] - '0')));
				}
				break;
			case'n':
			case'u':
			case't':
			case'0':
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case' ':
			case'\'':break;
			default:printf("error:%c", p[j]); break;
			}
			j++;
		}
		fprintf(fp, "s.add(s.ite(%s_%d == 0, %s_%d == 0, %s_%d == 3))\n", ch, i, Ch, i, Ch, i);
	}
	fprintf(fp, "s.add(%s == ", sum);
	for (i = 0; i < 15; i++)
	{
		fprintf(fp, "%s_%d + ", Ch, i);
	}
	fprintf(fp, "%s_15)\n", Ch);
}

void Condition(FILE *fp)
{
	int i;
	u32 alpha[4] = { 0,0,0,1 };
	u32 beta[4] = { 0x0,0x0,0x0,0x80 };
	u32 gamma[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 l[4] = { 0x0,0x0,0x0,0x1 };
	u32 m[4] = { 0x0,0x0,0x0,0x80 };
	u32 n[4] = { 0x0,0x0,0x0,0x81ec5a00 };
	u32 h[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	for (i = 0; i < 128; i++)
	{
		fprintf(fp, "s.add(alpha_%d == %d)\n", i, (alpha[i / 32] >> (i % 32)) & 1);
		fprintf(fp, "s.add(beta_%d == %d)\n", i, (beta[i / 32] >> (i % 32)) & 1);
		fprintf(fp, "s.add(alpha_%d == %d)\n", i, (alpha[i / 32] >> (i % 32)) & 1);
		fprintf(fp, "s.add(l_%d == %d)\n", i, (l[i / 32] >> (i % 32)) & 1);
		fprintf(fp, "s.add(m_%d == %d)\n", i, (m[i / 32] >> (i % 32)) & 1);
		fprintf(fp, "s.add(n_%d == %d)\n", i, (n[i / 32] >> (i % 32)) & 1);
		fprintf(fp, "s.add(h_%d == %d)\n", i, (h[i / 32] >> (i % 32)) & 1);
	}
}

void Exclude(FILE *fp, u32 a[4], u32 b[4], u32 c[4], u32 d[4], u32 q[4], int k)
{
	int i;
	fprintf(fp, "tempa_%d = s.bitvec('tempa_%d', 1)\n", k, k);
	fprintf(fp, "tempb_%d = s.bitvec('tempb_%d', 1)\n", k, k);
	fprintf(fp, "tempc_%d = s.bitvec('tempc_%d', 1)\n", k, k);
	fprintf(fp, "tempd_%d = s.bitvec('tempd_%d', 1)\n", k, k);
	fprintf(fp, "tempq_%d = s.bitvec('tempq_%d', 1)\n", k, k);

	fprintf(fp, "s.add(tempa_%d == ", k);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "(a_%d ^ %d) | ", i, ((a[i / 32] >> (i % 32)) & 1));
	}
	fprintf(fp, "(a_127 ^ %d))\n", ((a[3] >> 31) & 1));

	fprintf(fp, "s.add(tempb_%d == ", k);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "(b_%d ^ %d) | ", i, ((b[i / 32] >> (i % 32)) & 1));
	}
	fprintf(fp, "(b_127 ^ %d))\n", ((b[3] >> 31) & 1));

	fprintf(fp, "s.add(tempc_%d == ", k);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "(c_%d ^ %d) | ", i, ((c[i / 32] >> (i % 32)) & 1));
	}
	fprintf(fp, "(c_127 ^ %d))\n", ((c[3] >> 31) & 1));

	fprintf(fp, "s.add(tempd_%d == ", k);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "(d_%d ^ %d) | ", i, ((d[i / 32] >> (i % 32)) & 1));
	}
	fprintf(fp, "(d_127 ^ %d))\n", ((d[3] >> 31) & 1));

	fprintf(fp, "s.add(tempq_%d == ", k);
	for (i = 0; i < 127; i++)
	{
		fprintf(fp, "(q_%d ^ %d) | ", i, ((q[i / 32] >> (i % 32)) & 1));
	}
	fprintf(fp, "(q_127 ^ %d))\n", ((q[3] >> 31) & 1));

	fprintf(fp, "s.add(tempa_%d | tempb_%d | tempc_%d | tempd_%d | tempq_%d == 1)\n", k, k, k, k, k);
}

void sumup(FILE *fp)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 32; j++)
		{
			fprintf(fp, "s.add(s.ite(alpha_%d == 0, (alphat_%d >> %d) & 1 == 0, (alphat_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(beta_%d == 0, (betat_%d >> %d) & 1 == 0, (betat_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(gamma_%d == 0, (gammat_%d >> %d) & 1 == 0, (gammat_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(a_%d == 0, (at_%d >> %d) & 1 == 0, (at_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(b_%d == 0, (bt_%d >> %d) & 1 == 0, (bt_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(c_%d == 0, (ct_%d >> %d) & 1 == 0, (ct_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(u_%d == 0, (ut_%d >> %d) & 1 == 0, (ut_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(v_%d == 0, (vt_%d >> %d) & 1 == 0, (vt_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(w_%d == 0, (wt_%d >> %d) & 1 == 0, (wt_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(p_%d == 0, (pt_%d >> %d) & 1 == 0, (pt_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);
			fprintf(fp, "s.add(s.ite(q_%d == 0, (qt_%d >> %d) & 1 == 0, (qt_%d >> %d) & 1 == 1))\n", (32 * i + j), i, j, i, j);

		}
	}
}

void end(FILE *fp, unsigned __int32 lim)
{
	fprintf(fp, "s.add(Total == M1 + M2 + M3 + M4 + S1 + S2 + S3)\n");
	fprintf(fp, "s.add(Total < %d)\n", lim);
	fprintf(fp, "print s.check()\n");
	fprintf(fp, "print s.model()\n");
}

void doing()
{
	char a[] = "a";
	char b[] = "b";
	char c[] = "c";
	char d[] = "d";
	char e[] = "e";
	char f[] = "f";
	char h[] = "h";
	char g1[] = "g1";
	char g2[] = "g2";
	char g3[] = "g3";
	char g4[] = "g4";
	char g5[] = "g5";
	char l[] = "l";
	char m[] = "m";
	char n[] = "n";
	char A[] = "A";
	char B[] = "B";
	char C[] = "C";
	char alpha[] = "alpha";
	char beta[] = "beta";
	char gamma[] = "gamma";
	char x[] = "x";
	char X[] = "X";
	char y[] = "y";
	char Y[] = "Y";
	char z[] = "z";
	char Z[] = "Z";
	char t[] = "t";
	char T[] = "T";
	char p[] = "p";
	char q[] = "q";
	char u[] = "u";
	char v[] = "v";
	char w[] = "w";
	char A1[] = "A1";
	char B1[] = "B1";
	char C1[] = "C1";
	char S1[] = "S1";
	char S2[] = "S2";
	char S3[] = "S3";
	char M1[] = "M1";
	char M2[] = "M2";
	char M3[] = "M3";
	char M4[] = "M4";


	FILE *fp;
	fp = fopen("snow.py", "w");
	Model(fp);
	Nonzero(fp);
	LFSR(fp);
	exchange(fp, e, l, g1);
	exchange(fp, f, m, g2);
	exchange(fp, n, d, g3);
	exchange(fp, b, beta, g4);
	exchange(fp, d, h, g5);
	Sigma(fp);
	//Identity(fp);

	u32 a1[4] = { 0x0,0x0,0x0,0xc1000000 };
	u32 b1[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 c1[4] = { 0x0,0x0,0x0,0x1 };
	u32 d1[4] = { 0x0,0,0,0 };
	u32 q1[4] = { 0x0,0,0,0xc0 };

	u32 a2[4] = { 0x0,0x0,0x0,0xc1000000 };
	u32 b2[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 c2[4] = { 0x0,0x0,0x0,0x1 };
	u32 d2[4] = { 0x0,0,0,0 };
	u32 q2[4] = { 0x0,0,0,0x88 };

	u32 a3[4] = { 0x0,0x0,0x0,0xa1000000 };
	u32 b3[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 c3[4] = { 0x0,0x0,0x0,0x1 };
	u32 d3[4] = { 0x0,0,0,0 };
	u32 q3[4] = { 0x0,0,0,0xc0 };

	u32 a4[4] = { 0x0,0x0,0x0,0xa1000000 };
	u32 b4[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 c4[4] = { 0x0,0x0,0x0,0x1 };
	u32 d4[4] = { 0x0,0,0,0 };
	u32 q4[4] = { 0x0,0,0,0xa0 };

	u32 a5[4] = { 0x0,0x0,0x0,0xc1000000 };
	u32 b5[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 c5[4] = { 0x0,0x0,0x0,0x1 };
	u32 d5[4] = { 0x0,0,0,0 };
	u32 q5[4] = { 0x0,0,0,0xa0 };

	u32 a6[4] = { 0x0,0x0,0x0,0xc1000000 };
	u32 b6[4] = { 0x0,0x0,0x0,0x81ec5a80 };
	u32 c6[4] = { 0x0,0x0,0x0,0x1 };
	u32 d6[4] = { 0x0,0,0,0 };
	u32 q6[4] = { 0x0,0,0,0x90 };

	//Mo8jia(fp, a, g3, gamma, x, X, M1);
	//Mo8jia(fp, g4, g5, u, y, Y, M2);
	//Mo8jia(fp, e, c, alpha, z, Z, M3);
	//Mo8jia(fp, f, q, beta, t, T, M4);
	Mo32jia(fp, a, g3, gamma, x, X, M1);
	Mo32jia(fp, g4, g5, u, y, Y, M2);
	Mo32jia(fp, e, c, alpha, z, Z, M3);
	Mo32jia(fp, f, q, beta, t, T, M4);
	AES_P(fp, v, g5);
	AES_P(fp, w, b);
	AES_P(fp, p, gamma);
	SboxR(fp, alpha, v, A, A1, S1);
	SboxR(fp, c, w, B, B1, S2);
	SboxR(fp, q, p, C, C1, S3);
	//Condition(fp);
	//Exclude(fp, a1, b1, c1, d1, q1, 1);
	//Exclude(fp, a2, b2, c2, d2, q2, 2);
	//Exclude(fp, a3, b3, c3, d3, q3, 3);
	//Exclude(fp, a4, b4, c4, d4, q4, 4);
	//Exclude(fp, a5, b5, c5, d5, q5, 5);
	//Exclude(fp, a6, b6, c6, d6, q6, 6);
	//sumup(fp);
	end(fp, 480001);
}

int main()
{
	doing();
}
