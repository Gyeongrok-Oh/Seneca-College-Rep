package com.example.myapplication;

import java.io.Serializable;

public class Customer implements Serializable {

    private String name;
    private String phone;
    private String city;
    private ProcessStatus processStatus;

    private String status;

    public Customer(String name, String phone, String city, ProcessStatus processStatus) {
        this.name = name;
        this.phone = phone;
        this.city = city;
        this.processStatus = processStatus;
    }

    public String getName() {
        return name;
    }

    public String getPhone() {
        return phone;
    }

    public String getCity() {
        return city;
    }

    public String getStatus() {
        return status;
    }

    public ProcessStatus getProcessStatus() {
        return processStatus;
    }
}
