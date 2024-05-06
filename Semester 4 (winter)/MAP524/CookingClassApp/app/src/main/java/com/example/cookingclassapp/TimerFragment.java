package com.example.cookingclassapp;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class TimerFragment extends Fragment {

    private TextView timerTextView;
    private SeekBar seekBar;
    private ProgressBar progressBar;
    private Button startButton;
    private Button pauseButton;
    private Button resetButton;

    private TextView ingredientsTextView;
    private TextView instructionsTextView;

    private CountDownTimer countDownTimer;
    private long totalTimeMillis;
    private long timeLeftMillis;

    private long cookingTimeMillis;

    public TimerFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_timer, container, false);


        Bundle args = getArguments();
        if (args != null) {
            cookingTimeMillis = args.getLong("cookingTimeMillis", 0);
        }


        timeLeftMillis = cookingTimeMillis;


        timerTextView = view.findViewById(R.id.textViewTimer);
        if (timerTextView != null) {

            long minutes = cookingTimeMillis / 60000;
            long seconds = (cookingTimeMillis % 60000) / 1000;
            String timerText = String.format("%02d:%02d", minutes, seconds);
            timerTextView.setText(timerText);
        }



        return view;
    }




    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        timerTextView = view.findViewById(R.id.textViewTimer);
        seekBar = view.findViewById(R.id.seekBarTimer);
        progressBar = view.findViewById(R.id.progressBarTimer);
        startButton = view.findViewById(R.id.btnStart);
        pauseButton = view.findViewById(R.id.btnPause);
        resetButton = view.findViewById(R.id.btnReset);


        totalTimeMillis = 600000; // 10 minutes example

        setupSeekBar();
        setupButtons();
    }


    private void updateProgressBar(long remainingTimeMillis, long totalTimeMillis) {

        int progress = (int) remainingTimeMillis / 1000; // in seconds


        progressBar.setProgress(progress);
    }



    private void setupButtons() {
        startButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startTimer();
            }
        });

        pauseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                pauseTimer();
            }
        });

        resetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                resetTimer();
            }
        });
    }

    private void startTimer() {
        countDownTimer = new CountDownTimer(timeLeftMillis, 1000) {
            @Override
            public void onTick(long millisUntilFinished) {
                timeLeftMillis = millisUntilFinished;
                updateTimerText();

                // Pass remaining time and total time to updateProgressBar
                updateProgressBar(millisUntilFinished, totalTimeMillis);
                updateSeekBar(millisUntilFinished, totalTimeMillis);
            }

            @Override
            public void onFinish() {

                resetTimer();
            }
        }.start();


        seekBar.setEnabled(false);
        startButton.setEnabled(false);
        pauseButton.setEnabled(true);
        resetButton.setEnabled(true);
    }
    private void pauseTimer() {
        countDownTimer.cancel();


        seekBar.setEnabled(true);
        startButton.setEnabled(true);
        pauseButton.setEnabled(false);
        resetButton.setEnabled(true);
    }

    private void resetTimer() {
        countDownTimer.cancel();
        timeLeftMillis = totalTimeMillis;


        seekBar.setProgress(0);
        seekBar.setEnabled(true);
        startButton.setEnabled(true);
        pauseButton.setEnabled(false);
        resetButton.setEnabled(false);
        progressBar.setProgress(0);

        updateTimerText();
    }

    private void updateTimerText() {

        @SuppressLint("DefaultLocale") String formattedTime = String.format("%02d:%02d",
                timeLeftMillis / 60000,
                (timeLeftMillis % 60000) / 1000);
        timerTextView.setText(formattedTime);
    }



    public static TimerFragment newInstance(long cookingTimeMillis) {
        TimerFragment fragment = new TimerFragment();
        Bundle args = new Bundle();
        args.putLong("cookingTimeMillis", cookingTimeMillis);
        fragment.setArguments(args);
        return fragment;
    }


    private void updateSeekBar(long remainingTimeMillis, long totalTimeMillis) {

        int progress = (int) (totalTimeMillis - remainingTimeMillis) / 1000;


        seekBar.setProgress(progress);
    }


    private void setupSeekBar() {
        seekBar.setMax((int) totalTimeMillis / 1000);

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

                timeLeftMillis = totalTimeMillis - (progress * 1000);
                updateTimerText();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }


}
