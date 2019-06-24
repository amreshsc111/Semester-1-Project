#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
typedef struct
{
	char ID[10];
	char lastname[30];
	char firstname[30];
	int roll_no;
	char address[30];
	char level[30];
	char department[50];
	char year[30];
	long unsigned int phno;

	struct result{
		int iit;
		int c;
		int dl;
		int maths;
		int phy;
	}marks;
}student;
FILE *fp;

student readscreen(student rec)
{
	printf("\nID:");
	scanf("%s",&rec.ID);
	printf("Last Name:");
	scanf("%s",&rec.lastname);
	printf("First Name:");
	scanf("%s",&rec.firstname);
	printf("Roll Number:");
	scanf("%d",&rec.roll_no);
	printf("Address:");
	scanf("%s",&rec.address);
	printf("Level:");
	scanf("%s",&rec.level);
	printf("Department:");
	scanf("%s",&rec.department);
	printf("Year:");
	scanf("%s",&rec.year);
	printf("Phone Number:");
	scanf("%ld",&rec.phno);
	printf("Marks:\n");
	printf("Introduction to Information Technology:");
	scanf("%d",&rec.marks.iit);
	printf("C Programming:");
	scanf("%d",&rec.marks.c);
	printf("Digital Logic:");
	scanf("%d",&rec.marks.dl);
	printf("Mathematics I:");
	scanf("%d",&rec.marks.maths);
	printf("Physics:");
	scanf("%d",&rec.marks.phy);
	return(rec);
}
student writefile(student rec)
{
    fwrite(&rec,sizeof(rec),1,fp);
	fclose(fp); 
}

student add_student(student rec)
{
	char op;
    printf("\n\nAdd Record\n");
    fp = fopen("Student Record.txt","a");
    if(fp == NULL)
	{
        printf("Error in Opening file");
        exit(1);
    }
	else
	{
		fflush(stdin);
		x:printf("\nID:");
	    scanf("%s",&rec.ID);
	    printf("Last Name:");
	    scanf("%s",&rec.lastname);
	    printf("First Name:");
	    scanf("%s",&rec.firstname);
	    printf("Roll Number:");
	    scanf("%d",&rec.roll_no);
	    printf("Address:");
	    scanf("%s",&rec.address);
	    printf("Level:");
	    scanf("%s",&rec.level);
	    printf("Department:");
	    scanf("%s",&rec.department);
	    printf("Year:");
	    scanf("%s",&rec.year);
        printf("Phone Number: ");scanf("%ld",&rec.phno);
        printf("Marks Obtained:\n");
        printf("Introduction to Information Technology:");
        scanf("%d",&rec.marks.iit);
        printf("C Programming:");
        scanf("%d",&rec.marks.c);
        printf("Digital Logic:");
        scanf("%d",&rec.marks.dl);
        printf("Mathematics I:");
        scanf("%d",&rec.marks.maths);
        printf("Physics:");
        scanf("%d",&rec.marks.phy);
        fwrite(&rec,sizeof(rec),1,fp);             
		printf("The record is sucessfully added\n\n");
		printf("Do you wish to continue[Y/N]:");fflush(stdin);
		op=getchar();
		if(op=='Y'||op=='y')
		goto x;
    }
    fclose(fp);
    system("cls");
}

student search_student(student rec)
{
    printf("\nSearch Record\n");
    char s_id[10];
    int isFound=0;
    printf("Enter ID to Search: ");fflush(stdin);
    scanf("%s",&s_id);
    fp = fopen("Student Record.txt","r");
    if(fp==NULL)
    {
    	printf("File Not Found");
    	exit(1);
	}
    else
    {
    	while(fread(&rec,sizeof(rec),1,fp)==1)
    	{    
	        if(strcmp(s_id,rec.ID)==0)
	        {
	        	isFound=1;
	        	break;
	        }
	    }
	    if(isFound==1)
	    {
			printf("\nThe record is Found.");
			printf("\n\n%ID:%s\n",rec.ID);
            printf("Last Name:%s\n",rec.lastname);
            printf("First Name:%s\n",rec.firstname);
	        printf("Roll Number:%d\n",rec.roll_no);
	        printf("Address:%s\n",rec.address);
	        printf("%s%s\n","Level:",rec.level);
	        printf("Department:%s\n",rec.department);
	        printf("Year:%s\n",rec.year);
	        printf("Phone Number:%ld\n",rec.phno);
	        printf("Marks Secured:\n");
	        printf("Introduction to Information Technology:%d\n",rec.marks.iit);
	        printf("C Programming:%d\n",rec.marks.c);
	        printf("Digital Logic:%d\n",rec.marks.dl);
	        printf("Mathematics I:%d\n",rec.marks.maths);
	        printf("Physics:%d\n",rec.marks.phy);
		}
		else
		{
		    printf("\nThe record was not found.\n\n");
		}    
    }
    getch();
	fclose(fp);
	system("cls");
}

student mod_student(student rec)
{
	FILE *fpt;
	printf("\nModify Record\n");
    char id[10];
    int ch;
    printf("Enter ID to Modify: ");fflush(stdin);
    scanf("%s",id);
    fp = fopen("Student Record.txt","r");
    fpt=fopen("Tempfile.txt","w");
    while(fread(&rec,sizeof(rec),1,fp)==1)
    {
        if(strcmp(id,rec.ID)==0)
        {    
        	con:printf("\n1.Update ID");
        	printf("\n2.Update Last Name");
        	printf("\n3.Update First Name");
        	printf("\n4.Update Roll No.");
        	printf("\n5.Update Address");
        	printf("\n6.Update Level");
        	printf("\n7.Update Department");
        	printf("\n8.Update Year");
        	printf("\n9.Update Phone No.");
        	printf("\n\nEnter your choice:");
        	scanf("%d",&ch);
        	switch(ch)
        	{
        		case 1:
        			printf("Enter ID:");scanf("%s",&rec.ID);
        			break;
        		case 2:
        			printf("Last Name: ");scanf("%s",&rec.lastname);
        			break;
        		case 3:
        			printf("First Name: ");scanf("%s",&rec.firstname);
        			break;
        		case 4:
        			printf("Roll Number: ");scanf("%d",&rec.roll_no);
        			break;
        		case 5:
        			printf("Address: ");scanf("%s",&rec.address);
        			break;
        		case 6:
   				    printf("Level: ");scanf("%s",&rec.level);
   					break;
                case 7:
				    printf("Department: ");scanf("%s",&rec.department);
                    break;
                case 8:
		            printf("Year: ");scanf("%s",&rec.year);
		            break;
		        case 9:
                    printf("Phone Number: ");scanf("%ld",&rec.phno);
                    break;
                default:
                	printf("Invalid Input!!");
                	break;
            }
		}
		printf("\nRECORD UPDATED\n");
        if(ch>=1&&ch<=9)
        {
        	goto con;
        }
		fwrite(&rec, sizeof(rec),1,fpt);				    	
    }
	fclose(fp);
	fclose(fpt);
	fp = fopen("Student Record.txt","w");
    fpt=fopen("Tempfile.txt","r");
    while(fread(&rec,sizeof(rec),1,fpt)==1)
    {
    	fwrite(&rec,sizeof(rec),1,fp);
	}
	getch();
	fclose(fp);
	system("cls");
}

student gen_mark(student rec)
{
	printf("\nGenerate Marksheet:\n");
    char s_id[10];
    int i,j;
    int isFound=0;
    printf("Enter ID whose marksheet is to be generated: ");
    scanf("%s",&s_id);
    fp = fopen("Student Record.txt","r");
    if(fp==NULL)
    {
    	printf("File Not Found");
    	exit(1);
	}
	while(fread(&rec,sizeof(student),1,fp)==1)
	{
	 	if(strcmp(s_id,rec.ID)==0)
	 	{
	 		printf("\n\nID No.:%s\tLast Name:%s\tFirst Name:%s\n",rec.ID,rec.lastname,rec.firstname);
	 		printf("Roll No.:%d\tAddress:%s\tLevel:%s\n",rec.roll_no,rec.address,rec.level);
	 		printf("Department:%s\tYear:%s\t\tPhone No.:%ld\n",rec.department,rec.year,rec.phno);
	 		printf("\nSubjects\t\t\t\tMarks Obtained\n");
	 		printf("Introduction to Information Technology:\t\t%d",rec.marks.iit);
	 		printf("\nC Programming:\t\t\t\t\t%d",rec.marks.c);
	 		printf("\nDigital Logic:\t\t\t\t\t%d",rec.marks.dl);
	 		printf("\nMathematics I:\t\t\t\t\t%d",rec.marks.maths);
	 		printf("\nPhysics:\t\t\t\t\t%d",rec.marks.phy);
	 		fseek(fp,sizeof(student),SEEK_CUR);
			fwrite(&rec,sizeof(student),1,fp);
        }
        else
        {
        	printf("ERROR!!!");
		}  	
    }
	getch();
	fclose(fp);
}
student display(student rec)
{
	fp=fopen("Student Record.txt","r");
	while (fread(&rec,sizeof(rec),1,fp)==1)
	{
		printf("\n\nID No.:%s\tLast Name:%s\tFirst Name:%s\n",rec.ID,rec.lastname,rec.firstname);
	 	printf("Roll No.:%d\tAddress:%s\tLevel:%s\n",rec.roll_no,rec.address,rec.level);
	 	printf("Department:%s\tYear:%s\t\tPhone No.:%ld\n",rec.department,rec.year,rec.phno);
	 	printf("\nSubjects\t\t\t\tMarks Obtained\n");
	 	printf("Introduction to Information Technology:\t\t%d",rec.marks.iit);
	 	printf("\nC Programming:\t\t\t\t\t%d",rec.marks.c);
	 	printf("\nDigital Logic:\t\t\t\t\t%d",rec.marks.dl);
	 	printf("\nMathematics I:\t\t\t\t\t%d",rec.marks.maths);
	 	printf("\nPhysics:\t\t\t\t\t%d",rec.marks.phy);
	 	printf("\n\n------------------------------------------\n");
	}
	getch();
	fclose(fp);
	system("cls");
}

student delete(student rec)
{
	FILE *fpt;
	printf("\nDelete Record(s)\n\n");
	char id[10];
	printf("Enter ID to delete:");
	scanf("%s",&id);
	fp=fopen("Student Record.txt","r");
	fpt=fopen("Tempof.txt","w");
	while(fread(&rec,sizeof(rec),1,fp)==1)
	{
		if(strcmp(id,rec.ID) != 0)
		{
			fwrite(&rec,sizeof(rec),1,fpt);
		}
	}
	fclose(fp);
	fclose(fpt);
	fp = fopen("Student Record.txt", "w");
    fpt = fopen("Tempof.txt", "r");
    while (fread(&rec, sizeof(rec), 1, fpt)==1)
    {
        fwrite(&rec, sizeof(rec), 1, fp);
    }
	printf("The record is sucessfully deleted");
	getch();
	fclose(fp);
	fclose(fpt);
	system("cls");
}


void main()
{
	system("COLOR F8");
    int flag=TRUE;
    student rec;
    char another;
    char choice;
    if((fp=fopen("Student Record.txt","r"))==NULL)
    {
    	fp=fopen("Student Record.txt","a");
    	printf("\t\t\t\tStudent Record System\n\n");
        while(flag)
        {
        	printf("Do you wish to wrirte in fie record[Y/N]?\n");fflush(stdin);
        	scanf("%c",&another);
        	if(another=='Y'||another=='y')
        	{
    	        rec=readscreen(rec);
    	        writefile(rec);
    	    }
    	    else
    	    {
    	    	goto label;
			}
        }
	}
    
    label:system("cls");
    system("COLOR B4");
	while(TRUE)
	{
		system("cls");
	    printf("\n\t\t\t\tSTUDENT RECORD SYSTEM\n");
	    printf("\t\t\tMadan Bhandari Memorial College\n");
	    printf("\n\n*****Options*****\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Modify Student Record\n");
        printf("4. Generate Marksheet\n");
        printf("5. Display Records\n");
        printf("6. Delete Record(s)\n");
        printf("7. Exit\n");
        printf("\n\n------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%c",&choice);
        switch(choice)
		{
            case '1':
                system("cls");
                add_student(rec);
                break;
            case '2':
                system("cls");
            	search_student(rec);
            	break;
            case '3':
                system("cls");
			    mod_student(rec);
				break;	
            case '4':
                system("cls");
            	gen_mark(rec);
            	break;
            case '5':
            	system("cls");
            	display(rec);
            	break;
            case '6':
            	system("cls");
            	delete(rec);
            	break;
			case '7':
                exit(0);
                break;
            default:
                break;
        }
    }
    getch();
}

