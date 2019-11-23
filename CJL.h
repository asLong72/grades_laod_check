#ifndef CJL
#define CJL
#define _CJL_STUDENT_GRADES_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>


typedef struct studentgrade
{
	//char* inname;
	char name[7] = { NULL };
	char ID[11] = { NULL };
	//char sex[3] = { NULL };
	int gradei = 0;
	int grade[5] = { NULL };
};

typedef struct nodeleader
{
	nodeleader* lastp = NULL;
	studentgrade now;
	nodeleader* nextp = NULL;
}leader;

typedef struct linker
{
	leader* head=NULL;
	leader* tail=NULL;
}Linker;

leader* SG_File_Round_Check(FILE** fp, leader* sg);
void SG_CheckFor_name(leader* sg, char check[7]);
void SG_CheckFor_ID(leader* sg, char check[11]);
leader* SG_File_RaedIn(static FILE** fp, leader* sg);
void SG_print(static leader* sg);


void SG_Muem(void)
{
	printf("菜单\n");
	return;
}

/**/
leader* SG_creat(leader* sg)
{
	sg = (leader*)malloc(sizeof leader);
	sg->lastp = NULL;
	*(sg->now.name) = {NULL};
	*sg->now.ID = 0;
	sg->now.gradei = 0;
	*sg->now.grade = {NULL};
	sg->nextp = NULL;
	return sg;
}

/*读入和检查*/
int SG_Start_Check_GoOn(static FILE** fp, leader* sg)
{
	if (*fp == NULL)
	{
		return 1;
	}
	return 0;
}

leader* SG_File_Round_Check(static FILE** fp, leader* sg)
{
	if (SG_Start_Check_GoOn(fp, sg))
	{
		printf("error!\n");
		return NULL;
	}
	for (; fscanf(*fp, "%c") != EOF; )
	{
		fseek(*fp, -1L, 1);
		sg = SG_File_RaedIn(fp, sg);
	}
	printf("Finish!\n");
	return sg;
}

leader* SG_File_RaedIn(static FILE** fp, leader* sg)
{
	fscanf(*fp, "%6s,%10s,%d,%d,%d,%d,%d", sg->now.name, sg->now.ID, &sg->now.grade[0], &sg->now.grade[1], &sg->now.grade[2], &sg->now.grade[3], &sg->now.grade[4]);
	//fgets(sg.now.ID,10,fp);
	//fgets(sg.now.name, 5, fp);
	//fgets(sg.now.sex, 5, fp);
	//fgets(sg.now.grade, 4, fp);

	leader* sg_new = NULL;
	sg_new = SG_creat(sg_new);
	sg->nextp = sg_new;
	sg_new->lastp = sg;
	return sg_new;
}


/*检索和输出*/


void SG_find_RaedIntoCheck(Linker* sg)
{
	printf("请输入正确的名字或学号:\n");
	char tpye[11] = { NULL };
	scanf("%s", tpye);
	if (tpye[0] >= '0' && tpye[0] <= '9')
	{
		SG_CheckFor_ID(sg->head, tpye);
	}
	else if (tpye[0] < 0)
	{
		SG_CheckFor_name(sg->head, tpye);
	}
	else
	{
		printf("error!名字或学号格式不正确!\n");
	}
	//if (0 == strcmp(tpye , "name"))
	//{
	//	SG_CheckFor_ID(sg);
	//}
	//else if (0 == strcmp(tpye , "id"))
	//{
	//	SG_CheckFor_name(sg);
	//}
	return;
}

void SG_CheckFor_ID(leader* sg, char check[11])
{
	do
	{
		if (0 == strcmp(sg->now.ID, check))
		{
			printf("已找到该学生资料\n");
			SG_print(sg);
			break;
		}

	} while (1);
	return;
}

void SG_CheckFor_name(leader* head, char check[7])
{
	leader* p= head;
	for (; p;p=p->nextp )
	{
		if (0 == strcmp(p->now.name, check))
		{
			printf("已找到该学生资料\n");
			SG_print(p);
			break;
		}
	}
	return;
}

void SG_print(leader* sg)
{
	printf("需要查看%s哪一次成绩(1~5):", sg->now.name);
	scanf("%d", &sg->now.gradei);
	if (sg->now.gradei > 0 && sg->now.gradei < 6)
	{
		printf("%-s\t%-s\t%-d\n", sg->now.name, sg->now.ID, sg->now.grade[sg->now.gradei - 1]);
	}
	else
	{
		printf("error!输入的考试场次不存在!\n");
	}
	return;
}


#endif