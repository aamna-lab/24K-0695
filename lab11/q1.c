#include <stdio.h>
int main(){
	char buffer[30];
	FILE *ptr = fopen("idk.txt", "w");
	fprintf(ptr, "Example d4ta");
	fclose(ptr);
	FILE *ptrRead = fopen("idk.text", "r");
	FILE *ptr2 = fopen("idk1.txt" , "w");
	while ( fgets(buffer, sizeof(buffer), ptrRead)  != NULL){
		fputs(buffer, ptr2);
	}
	fclose(ptrRead);
	fclose(ptr2);
}
