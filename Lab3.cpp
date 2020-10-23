#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char * const argv[]){
	int counter_for_case_1 = 0;
	int counter_for_case_2 = 0;
	int counter_for_case_3 = 0;
	int counter_for_case_4 = 0;
    int i;
    int option_index = -1;

    const char* short_options = "hr::wi::";

    const struct option long_options[] = {
        {"help",0, NULL, 'h'},
        {"range",2, NULL, 'r'},
        {"whoami",0, NULL, 'w'},
        {"int",2, NULL, 'i'},
        {NULL,0,NULL,0}
    };
    while ((i=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){
    	switch (i) {
    		case 'h': {
    			if (counter_for_case_1 < 1){
    				if (option_index<0)
						printf("Arg: short help\n");
					else
						printf("Arg: long help\n");
    			};
                counter_for_case_1 ++;
    			break;
    		};
            case 'i':{
				if (counter_for_case_2 < 1)
					if (optarg != NULL)
						printf("Arg: int, Value of Integer: %s\n", optarg);
					else
						printf("Arg: int\n");
				counter_for_case_2 ++;
				break;
			};
    		case 'w': {
				if (counter_for_case_3 < 1)
					printf("Arg: who am I\n");
				counter_for_case_3 ++;
				break;
			};
			case 'l':{
				if (counter_for_case_4 < 1)
					if (option_index > 0)
                        if (optarg != NULL)
						    printf("Arg: range, elements of Range: %s\n", optarg);
					else
						printf("Arg: range\n");
				counter_for_case_4 ++;
				break;
			};
			default: {
				printf("I do not understand u\n");
				break;
			};
		};
		option_index = -1;

    };

};
