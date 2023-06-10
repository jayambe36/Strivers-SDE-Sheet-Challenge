string longestPalinSubstring(string str)    // function to find longest Palindrome Substring

{

    // Write your code here.    # Comment

    int n=str.length();    // initialize variable n with length of string

    int l,r;   //Initialize variables l, r

    int start=0;    // Initialize variable start with 0

    int end=1;    // Initialize variable end with 1

 

    for(int i=1;i<n;i++)    // loop through n-1 elements

    {

        //even substring    # even substring

        l=i-1;    // Assign value of l as i-1

        r=i;    // Assign value of r as i

 

        while(l>=0 && r<n && str[l]==str[r])    // loop while l>=0, r<n and str[l]==str[r]

        {

            if(r-l+1 > end)    // check if r-l+1 > end

            {

                start=l;    // Assign start with value of l

                end=r-l+1;    // assign end with value of r-l+1

                

            }

            l--;    // decrement l

            r++;    // increment r

        }

 

        // odd substring    # odd substring

        l=i-1;    // Assign value of l as i-1

        r=i+1;    // Assign value of r as i+1

 

        while(l>=0 && r<n && str[l]==str[r])    // loop while l>=0, r<n and str[l]==str[r]

        {

            if(r-l+1 > end)    // check if r-l+1 > end

            {

                start=l;    // Assign start with value of l

                end=r-l+1;    // assign end with value of r-l+1

                

            }

            l--;    //decrement l

            r++;    // increment r

        }

    }

    return str.substr(start,end);    // return substring of str from start to end

}
