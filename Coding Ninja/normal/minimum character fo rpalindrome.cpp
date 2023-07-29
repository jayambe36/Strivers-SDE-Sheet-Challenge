
int minCharsforPalindrome(string str) {
	// Write your code here.
	 int n = str.size();

    int i = 0;

    int j = n-1;

    int k = j;

 

    while(j >= i){

        if(str[i] != str[j]){

            i = 0;

            k--;

            j = k;

        }

        else{

            j--;

            i++;

        }

    }

 

    return n-1-k;
}
