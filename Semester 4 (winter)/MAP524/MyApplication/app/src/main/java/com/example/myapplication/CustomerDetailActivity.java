package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
public class CustomerDetailActivity extends AppCompatActivity {

    private TextView nameTextView, phoneTextView, cityTextView, statusTextView;
    private Button changeStatusButton, btnBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_customer_detail);


        nameTextView = findViewById(R.id.nameTextView);
        phoneTextView = findViewById(R.id.phoneTextView);
        cityTextView = findViewById(R.id.cityTextView);
        statusTextView = findViewById(R.id.statusTextView);
        changeStatusButton = findViewById(R.id.changeStatusButton);
        btnBack = findViewById(R.id.btnBack);

        Customer customer = getIntent().getParcelableExtra("customer");
        if (customer != null) {

            nameTextView.setText(customer.getName());
            phoneTextView.setText(customer.getPhone());
            cityTextView.setText(customer.getCity());
            statusTextView.setText(customer.getStatus());


            changeStatusButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {

                    Toast.makeText(CustomerDetailActivity.this, "Process status changed", Toast.LENGTH_SHORT).show();
                }
            });

            btnBack.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    onBackPressed();
                }
            });
        }
    }
}