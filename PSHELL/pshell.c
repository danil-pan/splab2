#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define max_length 100
int main(int argc, char *argv[]){
	int p[100];
	int n=0; 
	for ( ;; ) {
		printf("Give a command: ");
		char c[max_length];
		if (!fgets(c,100,stdin)){
			printf("good bye\n");
			break;
		}
		if (strcmp(c,"showjobs\n")==0){
			int i;
			for(i=0;i<n;i++){
				printf("[%d]\n",p[i]);
			}
		} else {
			int x = fork();
			if (x==0){
			  c[strlen(c)-1]=0; ///////
			  execlp(c,c,NULL);
			  exit(0);	    ///////
			}
			
			//waitpid(x,0,0); 
			p[n++]=x;
		}
	}
		
	return 0;
}
