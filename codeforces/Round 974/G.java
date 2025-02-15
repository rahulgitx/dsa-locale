import java.util.*;

public class G{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            long n = scanner.nextLong();
            long m = scanner.nextLong();
            long k = scanner.nextLong();

            long[][] days = new long[(int)n][2];

            for(int i=0; i<n; i++){
                days[i][0] = scanner.nextLong(); // day
                days[i][1] = scanner.nextLong(); // pint
            }



            // solution starts here
            long res = 0;
            Stack<Long[]> milkLeft = new Stack();
            for(int i=0; i<n; i++){
                long d = m;
                milkLeft.add(new Long[]{days[i][0], days[i][1]});
                long currDay = days[i][0];
                

                while(d > 0 && !milkLeft.isEmpty()){
                    Long[] top = milkLeft.pop();
                    long pint = top[1], day = top[0];
                    if(day+k-1 < currDay) break;
                    
                    if(pint >= d){
                        if(pint-d > 0) milkLeft.add(new Long[]{day, pint-d});
                        d = 0;
                        currDay++;
                    }
                    else{
                        d = d-pint;
                    }
                }
                if(d == 0) res++;
                //System.out.println("i:" + i + " res1: " + res + " stack.size(): " + milkLeft.size());
                
                if(i<n-1 && days[i+1][0]-days[i][0]==1) continue;

                long daysGap = i==n-1 ? 10000000000000L : days[i+1][0]-days[i][0]-1;
                long lastLeft = 0, lastLeftDay = 0;

                while(daysGap > 0 && !milkLeft.isEmpty()){
                    Long[] top = milkLeft.pop();
                    long pint = top[1], day = top[0]; 
                    //System.out.println("i:" + i + " day:" + day + " pint:" + pint + " currDay:" + currDay + " lastLeft:" + lastLeft + " lastLeftDay:" + lastLeftDay+ " gap:" + daysGap);
                    if(day+k-1 < currDay) break;

                    if(lastLeft > 0 && lastLeftDay+k-1 >= currDay){
                        if(m-lastLeft <= pint){
                            pint -= (m-lastLeft);
                            lastLeft = 0;
                            currDay++;
                            daysGap--;
                            res++;
                        }
                        else{
                            lastLeft += pint;
                            lastLeftDay = day;
                            pint = 0;
                        }
                        if(lastLeft != 0) continue;
                    }
                    else{
                        lastLeft = 0; lastLeftDay = 0;
                    }
                    //System.out.println("i:" + i  + " after lastleft pint:" + pint + " currDay:"+currDay+" lastLeft:"+lastLeft + " daysGap:" + daysGap);

                    long remainingFreshMilkDays = day+k - currDay;
                    long daysPintCanFeed = pint/m;


                    long usefulDays = Math.min(daysGap, Math.min(remainingFreshMilkDays, daysPintCanFeed));
                    res += usefulDays;
                    daysGap -= usefulDays;                    
                    pint = pint-(usefulDays*m);
                    currDay += usefulDays;
                    if(daysGap>0){
                        lastLeft = pint%m;
                        pint = 0;
                        lastLeftDay = day;
                    }
                    if(pint>0) milkLeft.add(new Long[]{day, pint});
                    //System.out.println("i:" + i + " useful:" + usefulDays + " pint:" + pint + " currDay:"+currDay+" lastLeft:"+lastLeft + " daysGap:" + daysGap);
                }
                //System.out.println("i:" + i + " res2: " + res + " stack.size(): " + milkLeft.size());
            }
            System.out.println(res);
        }
    }
}