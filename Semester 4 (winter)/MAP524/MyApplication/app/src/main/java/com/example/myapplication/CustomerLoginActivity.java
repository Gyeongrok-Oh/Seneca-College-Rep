package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class CustomerLoginActivity extends AppCompatActivity {

    private EditText usernameEditText;
    private EditText passwordEditText;
    private Button loginButton;
    private Button registerButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_customer_login);

        usernameEditText = findViewById(R.id.customerUsernameEditText);
        passwordEditText = findViewById(R.id.customerPasswordEditText);
        loginButton = findViewById(R.id.customerLoginButton);
        registerButton = findViewById(R.id.customerRegisterButton);

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String username = usernameEditText.getText().toString();
                String password = passwordEditText.getText().toString();


                if (isValid(username, password)) {

                    Toast.makeText(CustomerLoginActivity.this, "Login successful!", Toast.LENGTH_SHORT).show();

                } else {

                    Toast.makeText(CustomerLoginActivity.this, "Invalid username or password!", Toast.LENGTH_SHORT).show();
                }
            }
        });

        registerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(CustomerLoginActivity.this, CustomerRegisterActivity.class);
                startActivity(intent);
            }
        });
    }


    private boolean isValid(String username, String password) {

        return !username.isEmpty() && !password.isEmpty();
    }
}