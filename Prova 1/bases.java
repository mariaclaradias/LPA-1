import java.util.*;

class bases{


 public static void main(String[]Args){
    Scanner s = new Scanner(System.in);
    int vezes = Integer.parseInt(s.nextLine());

       
    for(int i=0; i< vezes; i++) {
        String linha = s.nextLine(); 
        String[] array = linha.split(" ");
        
        System.out.println("Case: "+(i+1));
        
        if(linha.contains("bin")){
            int bin=0;
            for(int j=0; j<array[0].length(); j++){
                if(array[0].charAt(j)=='1'){
                    bin += Math.pow(2,j);                
                }
            }               
            System.out.println(bin + " dec");

            String hex = Integer.toString(Integer.parseInt(array[0], 2), 16);

            System.out.println(hex + " hex");
            System.out.println();
                        
        }
        if(linha.contains("dec")){
            
            String hex = Integer.toString(Integer.parseInt(array[0], 10), 16);
            System.out.println(hex + " hex");

            String bin = Integer.toString(Integer.parseInt(array[0], 10), 2);    
            System.out.println(bin + " bin");
           
            System.out.println();        
        }
        if(linha.contains("hex")){
          
            String dec = Integer.toString(Integer.parseInt(array[0], 16), 10);
            System.out.println(dec + " dec");  

            String bin = Integer.toString(Integer.parseInt(array[0], 16), 2);
            System.out.println(bin + " bin");
            System.out.println();      
        }
    }

    
 }
}
