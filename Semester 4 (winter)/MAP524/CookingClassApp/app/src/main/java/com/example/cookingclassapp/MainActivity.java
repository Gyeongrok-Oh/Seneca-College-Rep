package com.example.cookingclassapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarView;

public class MainActivity extends AppCompatActivity {

    BottomNavigationView bottomNavigationView;

    HomeFragment homeFragment = new HomeFragment();

    RecipeFragment recipeFragment = new RecipeFragment();

    TimerFragment timerFragment = new TimerFragment();

    FeedbackFragment feedbackFragment = new FeedbackFragment();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bottomNavigationView = findViewById(R.id.bottom_nav);

        getSupportFragmentManager().beginTransaction()
                .add(R.id.container, homeFragment, "homeFragment")
                .add(R.id.container, recipeFragment, "recipeFragment")
                .hide(recipeFragment)
                .add(R.id.container, timerFragment, "timerFragment")
                .hide(timerFragment)
                .add(R.id.container, feedbackFragment, "feedbackFragment")
                .hide(feedbackFragment)
                .commit();

        bottomNavigationView.setOnItemSelectedListener(new NavigationBarView.OnItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                int id = item.getItemId();

                if (id == R.id.home) {
                    getSupportFragmentManager().beginTransaction().hide(recipeFragment).hide(timerFragment).hide(feedbackFragment).show(homeFragment).commit();
                    return true;
                } else if (id == R.id.recipe) {
                    getSupportFragmentManager().beginTransaction().hide(homeFragment).hide(timerFragment).hide(feedbackFragment).show(recipeFragment).commit();
                    return true;
                } else if (id == R.id.timer) {
                    getSupportFragmentManager().beginTransaction().hide(homeFragment).hide(recipeFragment).hide(feedbackFragment).show(timerFragment).commit();
                    return true;
                } else if (id == R.id.feedback) {
                    getSupportFragmentManager().beginTransaction().hide(homeFragment).hide(recipeFragment).hide(timerFragment).show(feedbackFragment).commit();
                    return true;
                }

                return false;
            }
        });


    }
}