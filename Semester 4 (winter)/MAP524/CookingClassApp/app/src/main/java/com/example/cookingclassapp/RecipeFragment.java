// RecipeFragment.java
package com.example.cookingclassapp;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class RecipeFragment extends Fragment {

    private RecyclerView recyclerView;
    public RecipeAdapter recipeAdapter;

    public RecipeFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_recipe, container, false);

        recyclerView = view.findViewById(R.id.recyclerViewRecipes);
        LinearLayoutManager layoutManager = new LinearLayoutManager(getContext());
        recyclerView.setLayoutManager(layoutManager);

        // 예시 데이터 생성
        List<Recipe> recipeList = generateRecipeData();

        // 어댑터 초기화
        recipeAdapter = new RecipeAdapter(recipeList);
        recyclerView.setAdapter(recipeAdapter);

        return view;
    }

    // 예시 레시피 데이터 생성
    private List<Recipe> generateRecipeData() {
        List<Recipe> recipeList = new ArrayList<>();
        recipeList.add(new Recipe("Chicken Stir Fry", R.drawable.chicken_stir_fry, "Ingredients for Chicken Stir Fry", "Instructions for Chicken Stir Fry", 500000)); // 7 minutes
        recipeList.add(new Recipe("Carbonara Pasta", R.drawable.cpasta_carbonara, "Ingredients for Carbonara Pasta", "Instructions for Carbonara Pasta", 300000)); // 5 minutes


        return recipeList;
    }

}
