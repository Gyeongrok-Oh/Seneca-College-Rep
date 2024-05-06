package com.example.myapplication;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.core.content.ContextCompat;
// CustomerHomeActivity.java

public class CustomerHomeActivity extends CustomerLoginActivity  {

    private Button btnLogout, btnEditDetails;
    private TextView textProcessStatus, textCustomerDetails;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_customer_home);


        btnLogout = findViewById(R.id.btn_logout);
        btnEditDetails = findViewById(R.id.btn_edit_details);
        textProcessStatus = findViewById(R.id.text_process_status);
        textCustomerDetails = findViewById(R.id.text_customer_details);


        btnLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(CustomerHomeActivity.this, CustomerLoginActivity.class);
                startActivity(intent);
                finish();
            }
        });


        btnEditDetails.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(CustomerHomeActivity.this, EditDetailsActivity.class);
                startActivity(intent);
            }
        });


        String customerDetails = "Name: John Doe\nPhone: 123-456-7890\nCity: New York"; // 고객 세부 정보 예시
        textCustomerDetails.setText(customerDetails);


        String processStatus = "AWAITED"; // 예시로 AWAITED로 설정
        textProcessStatus.setText("Process Status: " + processStatus);

        int textColor = getColorForProcessStatus(processStatus);
        textProcessStatus.setTextColor(textColor);
    }

    private int getColorForProcessStatus(String processStatus) {
        int colorResId;
        switch (processStatus) {
            case "AWAITED":
                colorResId = R.color.yellow;
                break;
            case "COMPLETED":
                colorResId = R.color.dark_green;
                break;

            default:
                colorResId = android.R.color.black;
        }
        return ContextCompat.getColor(this, colorResId);
    }
}
