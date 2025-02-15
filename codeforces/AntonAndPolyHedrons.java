import java.util.*;

public class AntonAndPolyHedrons{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        HashMap<String, Integer> mp = new HashMap<>();
        mp.put("Tetrahedron", 4);
        mp.put("Cube",6);
        mp.put("Octahedron",8);
        mp.put("Dodecahedron",12);
        mp.put("Icosahedron",20);

        int n = scanner.nextInt();
        scanner.nextLine();

        int res = 0;
        for(int i=0; i<n; i++){
            String s = scanner.nextLine();
            res += mp.get(s);
        }
        System.out.println(res);
    }
}