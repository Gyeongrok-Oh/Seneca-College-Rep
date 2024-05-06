package com.example.cookingclassapp;

import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.Switch;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class FeedbackFragment extends Fragment {

    private RatingBar ratingBar;
    private EditText editTextCookingNotes;
    private Switch switchShareFeedback;
    private Button submitButton;
    private String cookingNotes;
    private String rating;

    public FeedbackFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_feedback, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        ratingBar = view.findViewById(R.id.ratingBar);
        editTextCookingNotes = view.findViewById(R.id.editTextCookingNotes);
        switchShareFeedback = view.findViewById(R.id.switchShareFeedback);
        submitButton = view.findViewById(R.id.btnSubmitFeedback);

        Button shareButton = view.findViewById(R.id.btnShareFeedback);
        shareButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onShareFeedbackClick(v);
            }
        });


        submitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                submitFeedback();
            }
        });
    }

    public void onShareFeedbackClick(View view) {

        shareFeedbackWithOthers();
    }


    private void submitFeedback() {

        float rating = ratingBar.getRating();
        String cookingNotes = editTextCookingNotes.getText().toString();
        boolean shareFeedback = switchShareFeedback.isChecked();


        Toast.makeText(requireContext(), "Feedback submitted successfully!", Toast.LENGTH_SHORT).show();

        if (shareFeedback) {
            shareFeedbackWithOthers();
        }

    }

    private void shareFeedbackWithOthers() {

        String feedbackText = "Rating: " + rating + "\nCooking Notes: " + cookingNotes;


        Intent shareIntent = new Intent(Intent.ACTION_SEND);
        shareIntent.setType("text/plain");
        shareIntent.putExtra(Intent.EXTRA_TEXT, feedbackText);

        startActivity(Intent.createChooser(shareIntent, "Share Feedback"));
    }

}
