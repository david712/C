#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    int tmp1, tmp2, res, i;
    char data[64];

    fp1 = fopen("print_discharge_com4.log", "r");
    fp2 = fopen("edit.txt", "w");

    while(1){
        
        if(fscanf(fp1, "%s", data) == EOF) break;
        if('0' <= data[0] && data[0] <= '9')  {
            // 133226(1)
            fprintf(fp2, "%s ", data);
            // :
            fscanf(fp1, "%s", data);
            fprintf(fp2, "%s ", data);
            // 7405
            fscanf(fp1, "%s", data);
            fprintf(fp2, "%s \n", data);
        }
        else {
            // Print

            // start:133226
            fscanf(fp1, "%s", data);
            tmp1 = atoi(&data[6]);

            // end
            fscanf(fp1, "%s", data);

            // :133228
            fscanf(fp1, "%s", data);
            tmp2 = atoi(&data[1]);
            res = tmp2 - tmp1;
            for(i=0; i<res-1; i++){
                fprintf(fp2, "%d\n",++tmp1);
            }
            fprintf(fp2, "%s \n", &data[1]);
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
