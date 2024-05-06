package com.example.cookingclassapp;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class RecipeDetailActivity extends AppCompatActivity {
    public static final String EXTRA_RECIPE_INGREDIENTS = "extra_recipe_ingredients";
    public static final String EXTRA_RECIPE_INSTRUCTIONS = "extra_recipe_instructions";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_recipe_detail);


        String recipeIngredients = getIntent().getStringExtra(EXTRA_RECIPE_INGREDIENTS);
        String recipeInstructions = getIntent().getStringExtra(EXTRA_RECIPE_INSTRUCTIONS);


        TextView ingredientsTextView = findViewById(R.id.textViewRecipeIngredients);
        TextView instructionsTextView = findViewById(R.id.textViewRecipeInstructions);


        ingredientsTextView.setText(recipeIngredients);
        instructionsTextView.setText(recipeInstructions);
    }
}
