#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct employee
{
    int emp_id;
    char emp_name[MAX_LEN];
    int emp_gross_pay;
    int emp_loan_choice;
    union
    {
        int housing_loan;
        int education_loan;
        int personal_loan;
    } loanAmount;

} emp;

int main()
{
    emp employeeData;
    int userChoice;
    char userLoanChoice[MAX_LEN];

    scanf("%d", &employeeData.emp_id);
    scanf("%s", employeeData.emp_name);
    scanf("%d", &employeeData.emp_gross_pay);
    scanf("%d", &employeeData.emp_loan_choice);

    if ((employeeData.emp_loan_choice == 1) || (employeeData.emp_loan_choice == 2)
         || (employeeData.emp_loan_choice == 3))
    {
        if (employeeData.emp_loan_choice == 1)
        {
            strcpy(userLoanChoice, "Housing loan\0");
        }
        else if (employeeData.emp_loan_choice == 2)
        {
            strcpy(userLoanChoice, "Education loan\0");
        }
        else if (employeeData.emp_loan_choice == 3)
        {
            strcpy(userLoanChoice, "Personal loan\0");
        }
    }
    else
    {
        printf("Invalid input\n");
        return 0;
    }

    if (employeeData.emp_loan_choice == 1)
    {
        printf("%d \n", employeeData.emp_id);
        printf("%s \n", employeeData.emp_name);
        printf("%d \n", employeeData.emp_gross_pay);
        printf("%s \n", userLoanChoice);

        employeeData.loanAmount.housing_loan = 2.5 * (employeeData.emp_gross_pay);

        printf("%d \n", employeeData.loanAmount.housing_loan);
    }
    else if (employeeData.emp_loan_choice == 2)
    {
        printf("%d \n", employeeData.emp_id);
        printf("%s \n", employeeData.emp_name);
        printf("%d \n", employeeData.emp_gross_pay);
        printf("%s \n", userLoanChoice);

        employeeData.loanAmount.education_loan = (1.5) * (employeeData.emp_gross_pay);

        printf("%d \n", employeeData.loanAmount.education_loan);
    }
    else if (employeeData.emp_loan_choice == 3)
    {
        printf("%d \n", employeeData.emp_id);
        printf("%s \n", employeeData.emp_name);
        printf("%d \n", employeeData.emp_gross_pay);
        printf("%s \n", userLoanChoice);

        employeeData.loanAmount.personal_loan = (employeeData.emp_gross_pay);

        printf("%d \n", employeeData.loanAmount.personal_loan);
    }

    return 0;
}