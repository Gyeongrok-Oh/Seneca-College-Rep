package com.example.hackathoneventapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarView;

public class FeedbackActivity extends AppCompatActivity {

    enum SeekBarType {
        RED, GREEN, BLUE
    }

    private SeekBarType getSeekBarType(int id) {
        if (id == R.id.redSeekBar) return SeekBarType.RED;
        if (id == R.id.greenSeekBar) return SeekBarType.GREEN;
        if (id == R.id.blueSeekBar) return SeekBarType.BLUE;
        throw new IllegalArgumentException("Unknown SeekBar ID");
    }

    private int redValue = 255;
    private int greenValue = 255;
    private int blueValue = 255;
    private EditText feedbackEditText;
    private Button submitFeedbackButton;
    BottomNavigationView bottomNavigationView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_feedback);

        SeekBar redSeekBar = findViewById(R.id.redSeekBar);
        SeekBar greenSeekBar = findViewById(R.id.greenSeekBar);
        SeekBar blueSeekBar = findViewById(R.id.blueSeekBar);

        SeekBar.OnSeekBarChangeListener listener = new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                handleSeekBarChange(seekBar.getId(), progress);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        };

        redSeekBar.setOnSeekBarChangeListener(listener);
        greenSeekBar.setOnSeekBarChangeListener(listener);
        blueSeekBar.setOnSeekBarChangeListener(listener);

        feedbackEditText = findViewById(R.id.feedbackEditText);
        submitFeedbackButton = findViewById(R.id.submitFeedbackButton);

        submitFeedbackButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String feedback = feedbackEditText.getText().toString();

                // 피드백이 비어있지 않은 경우에만 처리
                if (!feedback.isEmpty()) {
                    // 여기에 피드백을 어떻게 처리할지 추가적인 코드를 작성하세요.
                    // 여기서는 간단히 토스트 메시지로 피드백을 보여줍니다.
                    Toast.makeText(FeedbackActivity.this, "Feedback: " + feedback, Toast.LENGTH_SHORT).show();
                } else {
                    // 피드백이 비어있을 경우 사용자에게 알림
                    Toast.makeText(FeedbackActivity.this, "Please enter your feedback", Toast.LENGTH_SHORT).show();
                }
            }
        });

        bottomNavigationView = findViewById(R.id.bottom_nav);
        bottomNavigationView.setSelectedItemId(R.id.feedback);

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
                    startActivity(new Intent(getApplicationContext(), RegisterActivity.class));
                    finish();
                    overridePendingTransition(0,0);
                    return true;
                }
                else if (id == R.id.feedback) {
                    return true;
                }
                return false;
            }
        });
    }

    private void handleSeekBarChange(int seekBarId, int progress) {
        switch (getSeekBarType(seekBarId)) {
            case RED:
                redValue = progress;
                break;
            case GREEN:
                greenValue = progress;
                break;
            case BLUE:
                blueValue = progress;
                break;
        }

        setBackgroundColor();
    }

    private void setBackgroundColor() {
        int color = android.graphics.Color.rgb(redValue, greenValue, blueValue);

        // Different ways to set background color

        // 1
        getWindow().getDecorView().setBackgroundColor(color);

        // 2
        View rootView = findViewById(android.R.id.content);
        rootView.setBackgroundColor(color);

        // 3
        LinearLayout mainLayout = findViewById(R.id.mainLayout);
        mainLayout.setBackgroundColor(color);
    }

}