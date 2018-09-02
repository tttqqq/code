package controller;

//抽象类或者接口用于内部类---此处用的抽象类
public abstract class Event {
    private long eventTime;
    protected final long delayTime;
    public Event(long delayTime){
        this.delayTime = delayTime;
        start();
    }

    public void start(){
        eventTime = System.nanoTime()+delayTime;
    }

    public boolean read(){
        return System.nanoTime()>=eventTime;
    }

    public abstract void action();
}
