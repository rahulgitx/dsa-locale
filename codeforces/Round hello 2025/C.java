import java.util.*;

public class C{
    public static boolean powerOf2(int n){
        if(n==1) return false;
        int a = 1;
        while(a<n) a = a*2;
        if(a==n) return true;
        return false;
    }
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t>0){
            t--;

            int l = sc.nextInt();
            int r = sc.nextInt();

            int mid = 0;
            boolean smallerThanr = false, greaterThanl = false;

            int start = 30;
            int i = start;
            while(i>=0){
                int lbit = (((1<<i)&l)>>i);
                int rbit = (((1<<i)&r)>>i);
                if(lbit != rbit) break;
                mid += (lbit<<i);
                i--;
            }
            // System.out.println(mid);

            start = i;
            for(i=start; i>=0; i--){
                int lbit = (((1<<i)&l)>>i);
                int rbit = (((1<<i)&r)>>i);
                int mBit = 0;

                if(lbit==1 || rbit==1) mBit=0;
                else mBit = 1;
                mid += (mBit<<i);
            }
            // System.out.println(mid);

            
            i = start;
            while(i>=0 && mid <= l){
                int mBit = (((1<<i)&mid)>>i);
                // System.out.println(i + " " + mBit + " " + mid);
                if(mBit==0 && ((mid + (1<<i)) < r)){
                    mid += (1<<i);
                }
                i--;
            }
            System.out.println(l + " " + mid + " " + r);
        }
    }
}