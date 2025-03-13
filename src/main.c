#include <stdio.h>


void welcomeMessage();
double inputNumber();
char operationSelection(double* actualNumber);
double operationEvaluation(double actualNumber, char operation);
double sum(double actualNumber);
double subtraction(double actualNumber);
double multiplication(double actualNumber);
double division(double actualNumber);
int closeApplication();

int main (){
	double actualNumber; 
	char operation;
	welcomeMessage();
	actualNumber = inputNumber();
	while(1){
		operation = operationSelection(&actualNumber);
		if(operation == 'b' && closeApplication()) break;
		printf("The result is: %lf\n", actualNumber);
	}
	
	return 0;
	

}

void welcomeMessage() {
	printf("\n\n\n");
	printf("░█████╗░░█████╗░██╗░░░░░░█████╗░██╗░░░██╗██╗░░░░░░█████╗░████████╗░█████╗░██████╗░\n");
	printf("██╔══██╗██╔══██╗██║░░░░░██╔══██╗██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗\n");
	printf("██║░░╚═╝███████║██║░░░░░██║░░╚═╝██║░░░██║██║░░░░░███████║░░░██║░░░██║░░██║██████╔╝\n");
	printf("██║░░██╗██╔══██║██║░░░░░██║░░██╗██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║░░██║██╔══██╗\n");
	printf("╚█████╔╝██║░░██║███████╗╚█████╔╝╚██████╔╝███████╗██║░░██║░░░██║░░░╚█████╔╝██║░░██║\n");
	printf("░╚════╝░╚═╝░░╚═╝╚══════╝░╚════╝░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝\n\n\n");
}

double inputNumber() {
	double d;
	int c;

	printf("Please, type a for the operation (for decimal values, please, use '.'): ");
	while (scanf("%lf", &d) != 1){
		while ((c = getchar()) != '\n' && c != EOF);
		printf("Invalid Input. Please enter a valid number: ");
	
	}

	while ((c = getchar()) != '\n' && c != EOF);
	
	return d;
}


char operationSelection(double* actualNumber){
	char selection;
	int c;

	while(1){
		printf("Select the operation: [1] Sum, [2] Subtraction, [3] Multiplication, [4] Division, [0] Clear, [b] Exit: ");
		scanf(" %c", &selection);
	
		while ((c = getchar()) != '\n' && c != EOF); 

		switch(selection){
			case '1':
				*actualNumber = sum(*actualNumber);
				return selection;
			case '2':
				*actualNumber = subtraction(*actualNumber);
				return selection;
			case '3':
				*actualNumber = multiplication(*actualNumber);
				return selection;
			case '4':
				*actualNumber = division(*actualNumber);
				return selection;
			case '0':
				*actualNumber = 0;
				return selection;
			case 'b':
				return selection;
			default: 
				printf("ERROR: Invalid Input\n");
		}

	}

}

int closeApplication(){
	char close;
	int c;

	printf("Close Application? [1] Yes, [0] No: ");

	while(1){
		scanf(" %c", &close);

		while((c = getchar()) != '\n' && c != EOF);
		if(close == '1' || close == '0') return close - '0';
		printf("Invalid Input. Please, try again: ");
	}

	return 1;	
	
}

double sum(double actualNumber) {
	double secondNumber;

	secondNumber = inputNumber();

	return actualNumber + secondNumber;
}

double subtraction(double actualNumber) {
	double secondNumber;

	secondNumber = inputNumber();

	return actualNumber - secondNumber;
}

double multiplication(double actualNumber) {
	double secondNumber;

	secondNumber = inputNumber();

	return actualNumber * secondNumber;
}

double division(double actualNumber){
	double secondNumber;

	while(1){
		secondNumber = inputNumber();
		if (secondNumber != 0) break;
		printf("ERROR: Invalid Input! Number must not be 0");
	}

	return actualNumber / secondNumber;
}
