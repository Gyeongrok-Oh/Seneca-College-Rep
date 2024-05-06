package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class AdminLoginActivity extends AppCompatActivity {

    private EditText adminUsernameEditText;
    private EditText adminPasswordEditText;
    private Button adminLoginButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admin_login);

        adminUsernameEditText = findViewById(R.id.adminUsernameEditText);
        adminPasswordEditText = findViewById(R.id.adminPasswordEditText);
        adminLoginButton = findViewById(R.id.adminLoginButton);

        adminLoginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (isValidAdminCredentials()) {
                    navigateToAdminHome();
                } else {
                    Toast.makeText(AdminLoginActivity.this, "Invalid credentials", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private boolean isValidAdminCredentials() {

        String username = adminUsernameEditText.getText().toString();
        String password = adminPasswordEditText.getText().toString();

        return username.equals("admin") && password.equals("password");
    }

    private void navigateToAdminHome() {
        Intent intent = new Intent(AdminLoginActivity.this, AdminHomeActivity.class);
        startActivity(intent);
        finish();
    }
}
