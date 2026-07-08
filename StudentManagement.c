#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[20];
    float marks;
};

int main()
{
    struct Student s;
    FILE *fp, *temp;
    int choice, id, found;

    while(1)
    {
        printf("\n1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                fp = fopen("student.txt", "ab");
                printf("Enter ID Name Marks: ");
                scanf("%d %s %f", &s.id, s.name, &s.marks);
                fwrite(&s, sizeof(s), 1, fp);
                fclose(fp);
                break;

            case 2:
                fp = fopen("student.txt", "rb");
                printf("\nStudent Records:\n");
                while(fread(&s, sizeof(s), 1, fp))
                {
                    printf("%d %s %.2f\n", s.id, s.name, s.marks);
                }
                fclose(fp);
                break;

            case 3:
                printf("Enter ID to Search: ");
                scanf("%d", &id);

                fp = fopen("student.txt", "rb");
                found = 0;

                while(fread(&s, sizeof(s), 1, fp))
                {
                    if(s.id == id)
                    {
                        printf("%d %s %.2f\n", s.id, s.name, s.marks);
                        found = 1;
                    }
                }

                if(found == 0)
                    printf("Record Not Found!");

                fclose(fp);
                break;

            case 4:
                printf("Enter ID to Update: ");
                scanf("%d", &id);

                fp = fopen("student.txt", "rb");
                temp = fopen("temp.txt", "wb");

                while(fread(&s, sizeof(s), 1, fp))
                {
                    if(s.id == id)
                    {
                        printf("Enter New Name and Marks: ");
                        scanf("%s %f", s.name, &s.marks);
                    }
                    fwrite(&s, sizeof(s), 1, temp);
                }

                fclose(fp);
                fclose(temp);
                remove("student.txt");
                rename("temp.txt", "student.txt");
                break;

            case 5:
                printf("Enter ID to Delete: ");
                scanf("%d", &id);

                fp = fopen("student.txt", "rb");
                temp = fopen("temp.txt", "wb");

                while(fread(&s, sizeof(s), 1, fp))
                {
                    if(s.id != id)
                        fwrite(&s, sizeof(s), 1, temp);
                }

                fclose(fp);
                fclose(temp);
                remove("student.txt");
                rename("temp.txt", "student.txt");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!");
        }
    }

    return 0;
}
