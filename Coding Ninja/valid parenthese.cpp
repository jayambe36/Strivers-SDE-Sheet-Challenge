bool isValidParenthesis(string s)

{

    // Write your code here.

    int rec1=0;

    int rec2=0;

    int cir1=0;

    int cir2=0;

    int cur1=0;

    int cur2=0;

    for(int i=0;i<s.length();i++){

        if(s[i]=='['){

            rec1=rec1+1;

        }

        else if(s[i]==']'){

            rec2=rec2+1;

        }

        else if(s[i]=='('){

            cir1=cir1+1;

        }

        else if(s[i]==')'){

            cir2=cir2+1;

        }

        else if(s[i]=='{'){

            cur1=cur1+1;

        }

        else if(s[i]=='}'){

            cur2=cur2+1;

        }

    }

 

    if((rec1==rec2)&&(cir1==cir2)&&(cur1==cur2)){

        return true;

    }

    else{

        return false;

    }

}