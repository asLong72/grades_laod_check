#include "CJL.h"

//C:\Users\14948\Desktop\grades.csv
int	main()
{
	char fn[80]={NULL};
	scanf("%s",fn);
	FILE* fp = fopen(fn, "r");
	Linker sg;

	sg.head = SG_creat(sg.head);

	sg.tail= SG_File_Round_Check(&fp, sg.head);

	SG_find_RaedIntoCheck(&sg);
	//printf("%-s\t%-s\t%-d\n",sg.now.name,sg.now.ID,sg.now.grade[sg.now.gradei]);
	//SG_print(&sg);

	fclose(fp);

	//char c[20] = { "³Â" }, d[20] = {0};
	//printf("%s%s%c", c,"³Â",c);
	//scanf("%s,%s", d,c);
	//printf("%s,%s", d,c);
	return 0;
}