package com.example.hackathoneventapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;

import android.widget.EditText;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarView;

public class RegisterActivity extends AppCompatActivity {

    private EditText mMsessageEditText;
    BottomNavigationView bottomNavigationView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);




        bottomNavigationView = findViewById(R.id.bottom_nav);
        bottomNavigationView.setSelectedItemId(R.id.register);

        bottomNavigationView.setOnItemSelectedListener(new NavigationBarView.OnItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                int id = item.getItemId();

                if (id == R.id.home) {
                    startActivity(new Intent(getApplicationContext(), MainActivity.class));
                    finish();
                    overridePendingTransition(0,0);
                    return true;
                }
                else if (id == R.id.explore) {
                    startActivity(new Intent(getApplicationContext(), ExploreActivity.class));
                    finish();
                    overridePendingTransition(0,0);
                    return true;
                }
                else if (id == R.id.register) {
                    return true;
                }
                else if (id == R.id.feedback) {
                    startActivity(new Intent(getApplicationContext(), FeedbackActivity.class));
                    finish();
                    overridePendingTransition(0,0);
                    return true;
                }
                return false;
            }
        });

    }


    public void DetailActivity(View view) {
        EditText etId = findViewById(R.id.etId);
        EditText etPassword = findViewById(R.id.etPassword);
        EditText etName = findViewById(R.id.etName);  // 수정 필요
        EditText etEmail = findViewById(R.id.etEmail);  // 수정 필요
        EditText etPhone = findViewById(R.id.etPhone);  // 수정 필요

        String id = etId.getText().toString();
        String password = etPassword.getText().toString();
        String name = etName.getText().toString();  // 수정 필요
        String email = etEmail.getText().toString();  // 수정 필요
        String phone = etPhone.getText().toString();  // 수정 필요

        Intent intent = new Intent(this, DetailActivity.class);  // 수정 필요

        intent.putExtra("Id", id);
        intent.putExtra("Password", password);
        intent.putExtra("Name", name);
        intent.putExtra("Email", email);
        intent.putExtra("Phone", phone);

        startActivity(intent);
    }



}