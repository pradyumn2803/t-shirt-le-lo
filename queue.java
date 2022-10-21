import java.util.*;
class Queue
{
    int st[]=new int[10];
    int f=0,r=0,cap=st.length,i;
    
    void pushValue(int v)
    {
        if(r<cap)
        st[r++]=v;
        else
        System.out.println("Overflow !!!");
    }
    int popValue()
    {
        if(f<r)
        return st[f++];
        else
        return -9999;
    }
    void display()
    {
        for(i=f;i<r;i++)
        {
            System.out.print(st[i]+" ");
        }    
    }
    void cal()
    {
        Scanner sc=new Scanner(System.in);
        int n,b,c;
        do
        {
            System.out.println("\n1.) Push");
            System.out.println("2.) Pop ");
            System.out.println("3.) Display ");
            System.out.println("4.) Quit ");
            n=sc.nextInt();
            switch(n)
            {
                case 1:System.out.print("Enter value:");
                       b=sc.nextInt();
                       pushValue(b);                       
                       break;
                case 2:c=popValue();
                       if(c<0)
                       System.out.println("\nQueue empty !!\nNo items to pop!! "); 
                       else
                       System.out.println("Popped element is : "+c);
                       break;
                case 3:if(r==f)
                       System.out.println("Queue empty !! ");
                       else
                       display();
                       break;
                case 4:System.out.println("Quitting the program !!! ");       
                       break;
                default:System.out.println("Not a valid choice!!! ");       
            }   
        }
        while(n != 4);
    }
}
