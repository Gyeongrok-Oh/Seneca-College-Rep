/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P2)
Full Name  : Gyeongrok oh
Student ID#: 119140226
Email      : goj3@myseneca.ca
Section    : NGG

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	const double TAX = 0.13;
	const char patSize = 'S', salSize = 'M', tomSize = 'L';
	float smallFrice, mediumPrice, largePrice;
	int pattyBuy, tommyBuy, sallyBuy, subTotalP, taxesP, totalPriceP, subTotalT, taxesT, totalPriceT, subTotalS, taxesS, totalPriceS, tBalance;
	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%f", &smallFrice);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%f", &mediumPrice);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%f", &largePrice);
	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2f\n", smallFrice);
	printf("MEDIUM : $%.2f\n", mediumPrice);
	printf("LARGE  : $%.2f\n", largePrice);
	printf("\n");
	printf("Patty's shirt size is '\%c\'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &pattyBuy);
	printf("\n");
	printf("Tommy's shirt size is '\%c\'\n", tomSize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &tommyBuy);
	printf("\n");
	printf("Sally's shirt size is '\%c\'\n", salSize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &sallyBuy);
	printf("\n");
	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	subTotalP = (((smallFrice * pattyBuy) + 0.005) * 100);
	taxesP = subTotalP * TAX + 0.5;
	totalPriceP = (taxesP + subTotalP + 0.5);
	printf("Patty    S    %.2f   %d  %7.4lf   %6.4f  %8.4f\n", smallFrice, pattyBuy, smallFrice * pattyBuy, taxesP / 100.0, totalPriceP / 100.0);
	subTotalS = (((mediumPrice * sallyBuy) + 0.005) * 100);
	taxesS = subTotalS * TAX + 0.5;
	totalPriceS = (taxesS + subTotalS + 0.5);
	printf("Sally    M    %.2f   %d  %7.4lf   %6.4f  %7.4f\n", mediumPrice, sallyBuy, mediumPrice * sallyBuy, taxesS / 100.0, totalPriceS / 100.0);
	subTotalT = (((largePrice * tommyBuy) + 0.005) * 100);
	taxesT = subTotalT * TAX + 0.5;
	totalPriceT = (taxesT + subTotalT + 0.5);
	printf("Tommy    L    %.2f   %d  %7.4lf   %6.4f  %7.4f\n", largePrice, tommyBuy, largePrice * tommyBuy, taxesT / 100.0, totalPriceT / 100.0);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("                         %8.4f   %6.4f  %7.4f\n", (smallFrice * pattyBuy) + (mediumPrice * sallyBuy) + (largePrice * tommyBuy), (taxesP / 100.0) + (taxesS / 100.0) + (taxesT / 100.0), (totalPriceP / 100.0) + (totalPriceS / 100.0) + (totalPriceT / 100.0));
	printf("\n");
	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n");
	printf("\n");
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");

	int noTax = ((smallFrice * pattyBuy) + (mediumPrice * sallyBuy) + (largePrice * tommyBuy)) * 100;
	printf("%22.4lf\n", noTax / 100.0);
	int tQ = (noTax / 100) / 2;
	tBalance = noTax % tQ;

	printf("Toonies %4d %9.4lf\n", tQ, tBalance / 100.0);
	int lBlance = tBalance / 100;
	int lQ = tBalance % 100;
	printf("Loonies %4d %9.4lf\n", lBlance, lQ / 100.0);
	int qBlance = lQ / 25;
	int qQ = lQ % 25;
	printf("Quarters %3d %9.4lf\n", qBlance, qQ / 100.0);
	int dBlance = qQ / 10;
	int dQ = qQ % 10;
	printf("Dimes %6d %9.4lf\n", dBlance, dQ / 100.0);
	int nBlance = dQ / 5;
	int nQ = dQ % 5;
	printf("Nickels %4d %9.4lf\n", nBlance, nQ / 100.0);
	int pBlance = nQ / 1;
	int pQ = nQ % 1;
	printf("Pennies %4d %9.4lf\n", pBlance, pQ / 100.0);
	printf("\n");
	float averageOne = (float)noTax / ((pattyBuy + sallyBuy + tommyBuy));
	printf("Average cost/shirt: $%.4f\n", averageOne / 100.0);
	printf("\n");
	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");

	printf("%22.4lf\n", (totalPriceP / 100.0) + (totalPriceS / 100.0) + (totalPriceT / 100.0));

	int yesTax = ((totalPriceP / 100.0) + (totalPriceS / 100.0) + (totalPriceT / 100.0)) * 100;

	int tQTwo = (yesTax / 100) / 2;
	int tBalanceTwo = yesTax % tQTwo;

	printf("Toonies %4d %9.4lf\n", tQTwo, tBalanceTwo / 100.0);

	int lBlanceTwo = tBalanceTwo / 100;
	int lQTwo = tBalanceTwo % 100;
	printf("Loonies %4d %9.4lf\n", lBlanceTwo, lQTwo / 100.0);

	int qBlanceTwo = lQTwo / 25;
	int qQTwo = lQTwo % 25;
	printf("Quarters %3d %9.4lf\n", qBlanceTwo, qQTwo / 100.0);

	int dBlanceTwo = qQTwo / 10;
	int dQTwo = qQTwo % 10;
	printf("Dimes  %5d %9.4lf\n", dBlanceTwo, dQTwo / 100.0);

	int nBlanceTwo = dQTwo / 5;
	int nQTwo = dQTwo % 5;
	printf("Nickels %4d %9.4lf\n", nBlanceTwo, nQTwo / 100.0);

	int pBlanceTwo = nQTwo / 1;
	int pQTwo = nQTwo % 1;
	printf("Pennies %4d %9.4lf\n\n", pBlanceTwo, pQTwo / 100.0);

	float averageTwo = (float)yesTax / ((pattyBuy + sallyBuy + tommyBuy));
	printf("Average cost/shirt: $%.4f\n", averageTwo / 100.0);
	return 0;
}



