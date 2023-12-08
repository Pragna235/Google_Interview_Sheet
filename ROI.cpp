/*

ROI
Problem Description
You must be aware of the concept of Stocks Portfolio. A stock portfolio is a collection of stock(s) that you invest into with an objective of making profit.

Stocks are bought and sold. Selling price minus buying price is realized profit or loss. In case a stock is not sold yet, if buying price is more than or less than the current stock market price, then it is termed as unrealized profit or loss, respectively.

Given information in form of <Quantity of Stock bought, time of purchase, time of sell, array of prices>, calculate the realized P/L and unrealized P/L at the given time.

Constraints
1<= No. Of Stocks (N) <=10^2

1<= Price of Stock <= 2*10^4

1<= M <= 365

1 <= Time of Purchase <= Time of Sell <= Length of list

Input
First line contains an integer N which denotes the number of stocks in the portfolio.

Next N lines contain a space separate tuple of 3 integers which denote < Quantity Bought, Time of Purchase, Time of Sell > for each stock. If the stock has not been sold, the Time of Sell will be 0.

The N+1 line contain an integer M which denotes number of days for which price of stock is provided

Then the next N lines contain M integers which denote the stock price from time T1 to TM.

The last line will be the time instance at which the the P/L needs to be computed.

Output
Print realized P/L on first line

Print unrealized P/L on the second line

Time Limit (secs)
1

Examples
Example 1

Input

3

10 4 20

10 1 11

100 6 0

22

113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 117

52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73

101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122

5

Output

0

60

Explaination

From input we know the following

Portfolio contains of 3 stocks. Quantity, time of purchase and time of selling is known for each stock
Stock prices of all 3 stocks in portfolio is given for 22 days
We also know that first line of the stock prices belong to first stock, second line to second stock, so on and so forth
We are interested in P/L position at the end of 5th day
After computation, we know that Stock 3 need not be considered since it is bought on Day 6 and we are computing P/L at end of Day 5. Stock 1 and Stock 2 have no Sell transaction on or before Day 5. Hence realized profit is zero. Substituting prices i.e. buy price and current market price at end of Day 5, we unnderstand that unrealized profit is [ (115 - 113) * 10 + (56 - 52) * 10] = 60. Hence unrealized P/L is 60.

Example 2

Input

3

10 4 20

10 1 11

100 6 0

22

113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 117

52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73

101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122

20

Output

120

1400

Explaination

Till day 20 we have brought all the above listed stocks and only two have been matured that is stock number 1 and 2 therefore the total realized profit is 20 + 100 = 120 and stock number 3 has not been sold therefore the total unrealized profit is 1400.

From input we know the following

Portfolio contains of 3 stocks. Quantity, time of purchase and time of selling is known for each stock
Stock prices of all 3 stocks in portfolio is given for 22 days
We also know that first line of the stock prices belong to first stock, second line to second stock, so on and so forth
We are interested in P/L position at the end of 20th day
After computation, we know that Stock 1, Stock 2 and Stock3 have been bought. Stock 1 and Stock 2 have Sell transaction at day 20 and 11 respectively. Substituting prices i.e. buy price and the market price at their respective sell date we understand he profit is [(115 - 113) * 10 + (62 - 52) * 10] = 120. Hence realized P/L is 120. Stock 3 have no sell transaction on or before Day 20 therefore we realize that the unrealized profit is [ (120 - 106) * 100] = 1400.

Example 3

Input

3

10 4 6

10 1 11

100 6 0

22

113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 113 115 112 117

52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73

101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122

10

Output

-10

490

Explaination

From input we know the following

Portfolio contains of 3 stocks. Quantity, time of purchase and time of selling is known for each stock
Stock prices of all 3 stocks in portfolio is given for 22 days
We also know that first line of the stock prices belong to first stock, second line to second stock, so on and so forth
We are interested in P/L position at the end of 10th day
After computation, we know that Stock 1, Stock 2 and Stock3 have been bought. Stock 1 have Sell transaction at day 6. Substituting prices i.e. buy price and the market price at their respective sell date we understand he profit is [(112 - 113) * 10] = -10. Hence realized P/L is -10. Stock 3 and Stock 2 have no sell transaction on or before Day 10 therefore we realize that the unrealized profit is [ (61 - 52) * 10 + (110 - 106) *100 ] = 490.

*/



#include<iostream>
using namespace std;

long long int p_or_l(long long int units, long long int top, long long int day, long long int prices[])
{
    //cout<<"-----Inside Function-----"<<endl;
    //cout<<endl<<"prices["<<day<<"] - prices["<<top<<"] = "<<prices[day]-prices[top]<<endl;
    //cout<<"Units = "<<units<<endl;
    //cout<<"Value returned = "<<(prices[day-1] - prices[top-1]) * units<<endl;
    return (prices[day-1] - prices[top-1]) * units;

}

int main()
{
    long long int n; //number of stocks
    //cout<<"Enter the value of n : ";
    cin>>n; //reading input n

    long long int stocks[n][3]; //array of n number of stocks with 3 columns (quantity of stock, time of purchase, time of sell)


    for(long long int i=0;i<n;i++){ //reading input array of stocks
        //cout<<endl<<"Enter the stock details (quantity, top, tos )["<<i<<"] : ";
        for(int j=0;j<3;j++){
            cin>>stocks[i][j];
        }
    }

    //cout<<endl<<"Enter the value of m : ";
    long long int m; //number of days for which the prices of stock are provided
    cin>>m; //reading input m

    long long int prices[n][m]; //prices array containing m days prices of n stocks


    for(long long int i=0;i<n;i++){ //reading input array of prices
        //cout<<endl<<"Enter the "<<m<<" no. of prices for the stock["<<i<<"] : ";
        for(long long int j=0;j<m;j++){
            cin>>prices[i][j];
        }
    }

    //cout<<endl<<"Enter the time instance day : ";
    long long int day; //time instance
    cin>>day; //reading input time instance

    long long int realized=0,unrealized=0; //realized and unrealized outputs

    //notes
    //cout<<endl<<"Initially realized = "<<realized<<" unrealized = "<<unrealized;
    for(long long int i=0;i<n;i++)
    {
        //cout<<endl<<"i = "<<i<<endl;
        if((stocks[i][1] <= day) && (stocks[i][2] <= day) && (stocks[i][2] != 0))
        {
            realized += p_or_l(stocks[i][0],stocks[i][1],stocks[i][2],prices[i]);
            //cout<<endl<<"realized = "<<realized;
        }

        else if((stocks[i][1] <= day) && ((stocks[i][2] > day) || (stocks[i][2] == 0) ))
        {
            unrealized += p_or_l(stocks[i][0],stocks[i][1],day,prices[i]);
            //cout<<"unrealized = "<<unrealized;
        }
    }


    cout<<realized<<endl;
    cout<<unrealized<<endl;
    //cout<<endl<<endl<<"Realized P/L   : "<<realized<<endl;
    //cout<<"Unrealized P/L : "<<unrealized<<endl;

    return 0;

}
