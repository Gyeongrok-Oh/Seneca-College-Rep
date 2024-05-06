package com.example.movieapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity implements MovieAdapter.OnItemClickListener {
    private RecyclerView recyclerView;
    private MovieAdapter adapter;
    private List<Movie> movieList;
    private static final int ADD_MOVIE_REQUEST_CODE = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        movieList = new ArrayList<>();
        movieList.add(new Movie("Movie Title 1", 2022, "tt123456", "Movie", "https://example.com/poster1.jpg"));
        movieList.add(new Movie("Movie Title 2", 2023, "tt654321", "Series", "https://example.com/poster2.jpg"));

        adapter = new MovieAdapter(movieList, this);
        recyclerView.setAdapter(adapter);

        findViewById(R.id.btnAddMovie).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, AddMovieActivity.class);
                startActivityForResult(intent, ADD_MOVIE_REQUEST_CODE);
            }
        });

        ItemTouchHelper.SimpleCallback itemTouchHelperCallback = new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) {
            @Override
            public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
                return false;
            }

            @Override
            public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
                // Swipe하여 삭제할 때의 동작
                int position = viewHolder.getAdapterPosition();
                removeMovie(position);
            }
        };
        new ItemTouchHelper(itemTouchHelperCallback).attachToRecyclerView(recyclerView);
    }


    private void removeMovie(int position) {
        movieList.remove(position);
        adapter.notifyItemRemoved(position);
    }

    @Override
    public void onItemClick(int position) {
        Movie selectedMovie = movieList.get(position);
        Intent intent = new Intent(MainActivity.this, MovieDetailsActivity.class);
        intent.putExtra("selectedMovie", selectedMovie);
        startActivity(intent);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == ADD_MOVIE_REQUEST_CODE && resultCode == RESULT_OK) {
            if (data != null) {
                String title = data.getStringExtra("title");
                int year = data.getIntExtra("year", 0);
                String imdbID = data.getStringExtra("imdbID");
                String type = data.getStringExtra("type");
                String posterUrl = data.getStringExtra("posterUrl");

                Movie newMovie = new Movie(title, year, imdbID, type, posterUrl);


                movieList.add(newMovie);
                adapter.notifyDataSetChanged();
            }
        }
    }
}


