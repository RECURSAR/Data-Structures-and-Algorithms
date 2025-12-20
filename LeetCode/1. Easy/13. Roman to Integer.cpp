int decesion = 0;
int priority(char, char);

class Solution {
public:
    int romanToInt(string s) {
    int i,j,sum = 0,temp;
    int VALUES[7] = {1,5,10,50,100,500,1000};
    i = 0;
    while(i!=s.length())
    {
        j=i+1;
        temp = priority(s[i],s[j]);
        if(decesion == 1)
        {
            sum = sum + temp;
            i++;
        }

        else 
        {
            sum = sum + temp;
            i+=2;
        }
    }
        return sum;
    }
};

int priority(char a, char b)
{
    char CHAR[7] = {'I','V','X','L','C','D','M'};
    int VALUES[7] = {1,5,10,50,100,500,1000};
    int x,y,value1,value2;

    for(int i=0; i<7; i++)
    {
        if(a==CHAR[i])
        {
            x = i;  
            value1 = VALUES[i];
        }   
        
        if(b==CHAR[i])
        {
            y = i;
            value2 = VALUES[i];
        }   
    }

    if(x > y || x - y == 0)         
    {
        decesion = 1;
        return value1;
    }    
    
    else                             
    {
        decesion = 0;
        return value2 - value1;
    }    
}