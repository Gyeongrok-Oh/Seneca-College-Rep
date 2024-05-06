// Recipe.java
package com.example.cookingclassapp;
public class Recipe {
    private String title;
    private int imageResourceId;
    private String ingredients;
    private String instructions;

    private long cookingTimeMillis;

    public Recipe(String title, int imageResourceId, String ingredients, String instructions, long cookingTimeMillis) {
        this.title = title;
        this.imageResourceId = imageResourceId;
        this.ingredients = ingredients;
        this.instructions = instructions;
        this.cookingTimeMillis = cookingTimeMillis;
    }

    public String getTitle() {
        return title;
    }

    public int getImageResourceId() {
        return imageResourceId;
    }

    public String getIngredients() {
        return ingredients;
    }

    public String getInstructions() {
        return instructions;
    }

    public long getCookingTimeMillis() {
        // Return the cooking time in milliseconds
        return cookingTimeMillis;
    }


}


