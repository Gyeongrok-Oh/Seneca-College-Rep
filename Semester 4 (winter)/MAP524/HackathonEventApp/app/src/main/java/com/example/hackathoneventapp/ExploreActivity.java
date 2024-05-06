package com.example.hackathoneventapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Switch;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarView;

import java.util.ArrayList;
import java.util.List;

public class ExploreActivity extends AppCompatActivity {

    public class Content {
        private String title;

        public Content(String title) {
            this.title = title;
        }

        public String getTitle() {
            return title;
        }
    }


    private ListView contentListView;
    private Switch categorySwitch;

    private List<Content> allContentList;
    private List<Content> specificCategoryContentList;

    BottomNavigationView bottomNavigationView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_explore);

        // Initialize views
        contentListView = findViewById(R.id.contentListView);
        categorySwitch = findViewById(R.id.categorySwitch);

        // Create sample content
        allContentList = createSampleContent(7);
        specificCategoryContentList = createSampleContent(2);

        // Set up ArrayAdapter for the ListView
        ArrayAdapter<Content> adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, allContentList);
        contentListView.setAdapter(adapter);

        // Set up Switch listener
        categorySwitch.setOnCheckedChangeListener((buttonView, isChecked) -> {
            // Handle switch state change
            if (isChecked) {
                // Show specific category content
                updateListViewWithSpecificCategory();
            } else {
                // Show all content
                updateListViewWithAllContent();
            }
        });

        bottomNavigationView = findViewById(R.id.bottom_nav);
        bottomNavigationView.setSelectedItemId(R.id.explore);

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
                    return true;
                }
                else if (id == R.id.register) {
                    startActivity(new Intent(getApplicationContext(), RegisterActivity.class));
                    finish();
                    overridePendingTransition(0,0);
                    return true;
                }
                else if (id == R.id.feedback) {
                    startActivity(new Intent(getApplicationContext(), FeedbackActivity.class));
                    finish();
                    overridePendingTransition(0,0);
                    return true;
                }

                return false;
            }
        });
    }
    private List<Content> createSampleContent(int count) {
        List<Content> contentList = new ArrayList<>();
        for (int i = 1; i <= count; i++) {
            Content content = new Content("Content " + i);
            contentList.add(content);
        }
        return contentList;
    }

    private void updateListViewWithSpecificCategory() {
        ArrayAdapter<Content> specificCategoryAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, specificCategoryContentList);
        contentListView.setAdapter(specificCategoryAdapter);
        Toast.makeText(this, "Showing specific category content", Toast.LENGTH_SHORT).show();
    }

    private void updateListViewWithAllContent() {
        ArrayAdapter<Content> allContentAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, allContentList);
        contentListView.setAdapter(allContentAdapter);
        Toast.makeText(this, "Showing all content", Toast.LENGTH_SHORT).show();
    }
}