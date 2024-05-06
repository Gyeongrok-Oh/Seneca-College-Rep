package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class EditDetailsActivity extends CustomerHomeActivity {

    private EditText editTextName, editTextPhone, editTextCity;
    private Button btnSave;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_details);


        editTextName = findViewById(R.id.edit_text_name);
        editTextPhone = findViewById(R.id.edit_text_phone);
        editTextCity = findViewById(R.id.edit_text_city);
        btnSave = findViewById(R.id.btn_save);


        btnSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                saveDetails();
            }
        });


        String name = ""; // Set to take the previous stored name
        String phone = ""; // Set to take the previous stored cell phone number
        String city = ""; // Set to take the previous stored city info
        editTextName.setText(name);
        editTextPhone.setText(phone);
        editTextCity.setText(city);
    }
    private void saveDetails() {

        String name = editTextName.getText().toString();
        String phone = editTextPhone.getText().toString();
        String city = editTextCity.getText().toString();

        updateDetails(name, phone, city);
    }

    private void updateDetails(String name, String phone, String city) {

        Toast.makeText(this, "세부 정보가 업데이트되었습니다.", Toast.LENGTH_SHORT).show();


        finish();
    }
}
