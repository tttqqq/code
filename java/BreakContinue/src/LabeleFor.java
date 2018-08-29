public class LabeleFor{
    public static void main(String[] args){
        int i = 0;
        outer:
//        System.out.println("run outer");
        for(;true;){
            System.out.println("run inner");
            inner:
            for(;i<10;i++){
                System.out.println("i = "+ i);
                if(i == 2){
                    System.out.println("continue");
                    continue;
                }
                if (3== i){
                    System.out.println("break");
                    i++;
                    break;
                }
                if (7==i){
                    System.out.println("continue outer");
                    i++;
                    continue outer;
                }
                if (8==i){
                    System.out.println("break outer");
                    break outer;
                }
                for (int k = 0; k<5; k++){
                    if (3==k){
                        System.out.println("continue inner");
                        continue inner;
                    }
                }
            }
        }
    }
}