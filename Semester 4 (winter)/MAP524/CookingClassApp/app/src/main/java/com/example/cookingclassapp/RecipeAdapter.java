package com.example.cookingclassapp;
import com.example.cookingclassapp.TimerFragment;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;
public class RecipeAdapter extends RecyclerView.Adapter<RecipeAdapter.RecipeViewHolder> {

    private List<Recipe> recipeList;

    public RecipeAdapter(List<Recipe> recipeList) {
        this.recipeList = recipeList;
    }

    @NonNull
    @Override
    public RecipeViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.recipe_item, parent, false);
        return new RecipeViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull RecipeViewHolder holder, int position) {
        Recipe recipe = recipeList.get(position);
        holder.bind(recipe);
    }

    @Override
    public int getItemCount() {
        return recipeList.size();
    }

    public class RecipeViewHolder extends RecyclerView.ViewHolder {
        ImageView thumbnailImageView;
        TextView titleTextView;
        TextView ingredientsTextView;
        TextView instructionsTextView;
        Button startCookingButton;

        public RecipeViewHolder(@NonNull View itemView) {
            super(itemView);
            thumbnailImageView = itemView.findViewById(R.id.imageViewThumbnail);
            titleTextView = itemView.findViewById(R.id.textViewRecipeTitle);
            ingredientsTextView = itemView.findViewById(R.id.textViewRecipeIngredients);
            instructionsTextView = itemView.findViewById(R.id.textViewRecipeInstructions);
            startCookingButton = itemView.findViewById(R.id.btnStartCooking);

            startCookingButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Recipe recipe = recipeList.get(getAdapterPosition());


                    TimerFragment fragment = new TimerFragment();
                    fragment.setArguments(createBundle(recipe.getCookingTimeMillis()));

                    ingredientsTextView.setText(recipe.getIngredients());
                    instructionsTextView.setText(recipe.getInstructions());

                    FragmentTransaction transaction = ((MainActivity) itemView.getContext()).getSupportFragmentManager().beginTransaction();
                    transaction.replace(R.id.fragmentContainer, fragment);
                    transaction.addToBackStack(null);
                    transaction.commit();
                }
            });
        }

        public void bind(Recipe recipe) {
            thumbnailImageView.setImageResource(recipe.getImageResourceId());
            titleTextView.setText(recipe.getTitle());
        }

        private Bundle createBundle(long cookingTimeMillis) {
            Bundle bundle = new Bundle();
            bundle.putLong("cookingTimeMillis", cookingTimeMillis);
            return bundle;
        }
    }
}

