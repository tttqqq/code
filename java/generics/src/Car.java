public class Car {
    private String name;
    private int years;

    public String getName() {
        return name;
    }
    public void setName(String name){
        this.name = name;
    }

    public int getYears() {
        return years;
    }
    public void  setYears(int years){
        this.years = years;
    }

    public String toString(){
        return "Car";
    }
}

class AngkelaCar extends Car{
    private int value;

    public int getValue(){
        return value;
    }
    public void setValue(int value){
        this.value = value;
    }
    public String toString(){
        return "AngkelaCar";
    }
}
