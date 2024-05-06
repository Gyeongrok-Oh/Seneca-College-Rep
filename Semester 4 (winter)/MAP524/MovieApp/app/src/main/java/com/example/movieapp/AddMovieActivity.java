package com.example.movieapp;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class AddMovieActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_movie);

        EditText editTextTitle = findViewById(R.id.editTextTitle);
        EditText editTextYear = findViewById(R.id.editTextYear);
        EditText editTextImdbID = findViewById(R.id.editTextImdbID);
        EditText editTextType = findViewById(R.id.editTextType);
        EditText editTextPosterUrl = findViewById(R.id.editTextPosterUrl);

        Button btnAdd = findViewById(R.id.btnAdd);
        btnAdd.setOnClickListener(v -> {
            String title = editTextTitle.getText().toString();
            int year = Integer.parseInt(editTextYear.getText().toString());
            String imdbID = editTextImdbID.getText().toString();
            String type = editTextType.getText().toString();
            String posterUrl = editTextPosterUrl.getText().toString();


            Movie newMovie = new Movie(title, year, imdbID, type, posterUrl);


            Intent resultIntent = new Intent();
            resultIntent.putExtra("title", title);
            resultIntent.putExtra("year", year);
            resultIntent.putExtra("imdbID", imdbID);
            resultIntent.putExtra("type", type);
            resultIntent.putExtra("posterUrl", posterUrl);
            setResult(RESULT_OK, resultIntent);
            finish();
        });
    }

}

