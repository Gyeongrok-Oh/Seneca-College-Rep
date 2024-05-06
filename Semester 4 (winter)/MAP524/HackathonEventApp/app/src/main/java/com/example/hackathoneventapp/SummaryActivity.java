package com.example.hackathoneventapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;

public class SummaryActivity extends AppCompatActivity {

    private RadioGroup userTypeRadioGroup;
    private ProgressBar userTypeProgressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_summary);

        Spinner spinnerGender = findViewById(R.id.gender_spinner);

        // Spinner에 사용할 배열 가져오기
        String[] genders = this.getResources().getStringArray(R.array.gender_spinner);

        // ArrayAdapter 설정
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, genders);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        // Spinner에 ArrayAdapter 설정
        spinnerGender.setAdapter(adapter);

        // RadioGroup, RadioButton, ProgressBar
        userTypeRadioGroup = findViewById(R.id.userTypeRadioGroup);
        userTypeProgressBar = findViewById(R.id.userTypeProgressBar);

        userTypeRadioGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                if (checkedId == R.id.adminRadioButton) {
                    userTypeProgressBar.setProgress(100);
                } else if (checkedId == R.id.userRadioButton) {
                    userTypeProgressBar.setProgress(70);
                } else if (checkedId == R.id.guestRadioButton) {
                    userTypeProgressBar.setProgress(30);
                }
            }
        });

        Intent intent = getIntent();

        String id = intent.getStringExtra("Id");
        String password = intent.getStringExtra("Password");
        String name = intent.getStringExtra("Name");
        String email = intent.getStringExtra("Email");
        String phone = intent.getStringExtra("Phone");

        TextView textView = findViewById(R.id.summary);
        textView.setText("User Id: " + id + "\nUser Password: " + password +
                "\nUser Name: " + name + "\nUser Email: " + email + "\nUser Phone: " + phone);

        String teamName = intent.getStringExtra("TeamName");
        String teamMember = intent.getStringExtra("TeamMember");
        String projectName = intent.getStringExtra("ProjectName");
        String projectDescription = intent.getStringExtra("ProjectDescription");

        textView.append("\nUser Team name: " + teamName + "\nUser Team member: " + teamMember +
                "\nUser Project name: " + projectName + "\nUser Project description:\n" + projectDescription);
    }


}