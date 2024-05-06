package com.example.hackathoneventapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class DetailActivity extends AppCompatActivity {

    private String id;
    private String password;
    private String name;
    private String email;
    private String phone;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);

        Intent intent = getIntent();
        String id = intent.getStringExtra("Id");
        String password = intent.getStringExtra("Password");
        String name = intent.getStringExtra("Name");
        String email = intent.getStringExtra("Email");
        String phone = intent.getStringExtra("Phone");

        TextView textView = findViewById(R.id.detail);
        textView.setText("User Id: " + id + "\nUser Password: " + password +
                "\nUser Name: " + name + "\nUser Email: " + email + "\nUser Phone: " + phone);
    }

    public void SummaryActivity(View view) {
        EditText etTeamName = findViewById(R.id.etTeamName);
        EditText etTeamMembers = findViewById(R.id.etTeamMembers);
        EditText etProjectName = findViewById(R.id.etProjectName);
        EditText etProjectDescription = findViewById(R.id.etProjectDescription);

        String teamName = etTeamName.getText().toString();
        String teamMember = etTeamMembers.getText().toString();
        String projectName = etProjectName.getText().toString();
        String projectDescription = etProjectDescription.getText().toString();

        Intent intent = new Intent(this, SummaryActivity.class);

        Intent registerIntent = getIntent();
        intent.putExtras(registerIntent); // Pass all extras from RegisterActivity

        intent.putExtra("TeamName", teamName);
        intent.putExtra("TeamMember", teamMember);
        intent.putExtra("ProjectName", projectName);
        intent.putExtra("ProjectDescription", projectDescription);



        startActivity(intent);
    }


}