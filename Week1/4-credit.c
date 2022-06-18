#include <cs50.h>
#include <stdio.h>
long get_card_number()
{
    long card_number;
    do
    {
        card_number = get_long("card_number: ");
    } while (card_number <= 0);
    return card_number;
}
long get_card_ans(long card_number)
{
    long card_number_out = 0;
    long card_number_1 = card_number / 10;
    long card_number_2 = 0;
    long card_number_3 = 0;

    while (card_number_1 > 0)
    {
        card_number_2 = card_number_1 % 10 * 2;
        if (card_number_2 < 10)
        {
            card_number_out += card_number_2;
        }
        else
        {
            card_number_out += card_number_2 % 10 + card_number_2 / 10;
        }
        card_number_1 = card_number_1 / 100;
    }

    card_number_1 = card_number;
    while (card_number_1 > 0)
    {
        card_number_3 = card_number_1 % 10;
        card_number_out += card_number_3;
        card_number_1 = card_number_1 / 100;
    }
    return card_number_out;
}

int main(void)
{
    long card_number = get_card_number();
    long card_ans = get_card_ans(card_number);
    int card_length = 2;
    long card_ans1 = card_number;
    while (card_ans1 >= 100)
    {
        card_ans1 = card_ans1 / 10;
        card_length++;
    }
    if (card_ans % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        /*    printf("%li\n",card_number);
            printf("%i\n",card_length);
            printf("%li\n",card_ans);
            printf("%li\n",card_ans1);**/
        if (card_length == 15 && (card_ans1 == 34 || card_ans1 == 37))
        {
            printf("AMEX\n");
        }
        else if (card_length == 16 && card_ans1 >= 51 && card_ans1 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((card_length == 13 || card_length == 16) && card_ans1 >= 40 && card_ans1 <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}