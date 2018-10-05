public class holder<T> {
    private T a;
    public holder(T a){
        this.a = a;
    }
    public void set(T a){
        this.a = a;
    }
    public T get(){
        return a;
    }
    public static void main(String[] args){
        holder<Car> newHolder = new holder<Car>(new Car());
        Car car = newHolder.get();
        car.setName("wangtingting");
        car.setYears(2017);
        System.out.println(car+" "+ car.getName()+" "+ car.getYears());

        holder<Car> newHolder1 = new holder<Car>(new AngkelaCar());
        Car angkela = newHolder1.get();
        angkela.setYears(2018);
        angkela.setName("chentaoquan");
        System.out.println(angkela+" "+ angkela.getName()+" "+ angkela.getYears());

        holder<AngkelaCar> newHolder2 = new holder<AngkelaCar>(new AngkelaCar());
        AngkelaCar angkela1 = newHolder2.get();
        angkela1.setYears(2019);
        angkela1.setName("ttqq");
        angkela1.setValue(99999999);
        System.out.println(angkela1+" "+ angkela1.getName()+" "+ angkela1.getYears()+" "+ angkela1.getValue());
    }
}
