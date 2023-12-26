-- ***********************
-- Name: Kittikom Kornmanakij
-- ID: 101169233
-- Date: 09-Dec-2023
-- Purpose: Assignment 2 - DBS301
-- ***********************

-- ***********************
-- Name: Supachai Ruknuy
-- ID: 121707228
-- Date: 09-Dec-2023
-- Purpose: Assignment 2 - DBS301
-- ***********************

-- ***********************
-- Name: GYEONGROK OH
-- ID: 119140226
-- Date: 09-Dec-2023
-- Purpose: Assignment 2 - DBS301
-- ***********************
--

SET SERVEROUTPUT ON;


--Object 1: spPlayersInsert
CREATE OR REPLACE PROCEDURE spPlayersInsert(
    p_playerId NUMBER,
    p_regnumber VARCHAR2,
    p_lastname VARCHAR2,
    p_firstname VARCHAR2,
    p_isactive NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN

     IF p_playerId <= 0 THEN
        -- Raise an exception for an invalid primary key
         out_result := -1;
    ELSE
        -- Insert data into the table
        INSERT INTO players
        VALUES (p_playerId, p_regnumber, p_lastname, p_firstname, p_isactive);
        
          -- Check if any rows were affected, -- check duplicate row
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE           
            -- Rows were affected, indicating successful deletion
            out_result := p_playerId;          
        END IF;
    
    END IF;

    COMMIT;
EXCEPTION
       WHEN OTHERS THEN out_result := -1; ROLLBACK;
        
END spPlayersInsert;

---------------------------- TEST spPlayersInsert --------------------------------
DECLARE
    out_pk NUMBER;
    
BEGIN
    spPlayersInsert(2323743,'A11110','Doe','John',1, out_pk);
    
        IF out_pk = -1 THEN
                DBMS_OUTPUT.PUT_LINE('Insertion failed.');
            ELSE
                DBMS_OUTPUT.PUT_LINE('Insert a new player ID: '||out_pk);
                
            END IF;      
END;
----------------------------------------------------------------------------------

---Object 2: spPlayersUpdate
CREATE OR REPLACE PROCEDURE spPlayersUpdate(
    p_playerId NUMBER,
    p_regnumber VARCHAR2,
    p_lastname VARCHAR2,
    p_firstname VARCHAR2,
    p_isactive NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
    -- Check if the primary key is valid
    IF p_playerId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;
        ROLLBACK;
    ELSE 
       -- Update data in the table
        UPDATE players
        SET regnumber = p_regnumber,
            lastname = p_lastname,
            firstname = p_firstname,
            isactive = p_isactive
        WHERE playerid = p_playerId;
                
        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE -- found data            
            -- Rows were affected, indicating successful deletion
            out_result := p_playerId;          
        END IF;
    
    END IF;
    
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spPlayersUpdate;
--------------------------------------------------------------------------------

-------------------------- TEST spPlayersUpdate --------------------------------
DECLARE
    v_result NUMBER;

BEGIN
    spPlayersUpdate(2323745,'X1110','Parker','Peter',1,v_result);

    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Update failed.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Update successful for Player ID: ' || v_result);
    END IF;

END;
--------------------------------------------------------------------------------

--Object 3 : spPlayersDelete
CREATE OR REPLACE PROCEDURE spPlayersDelete(
    p_playerId NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
      -- Check if the primary key is valid
    IF p_playerId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;     
    ELSE   
    
        DELETE FROM players WHERE playerid = p_playerId;

        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;         
        ELSE      
              -- Rows were affected, indicating successful deletion
            out_result := p_playerId;  
                          
        END IF;
        
    END IF;

    COMMIT;
EXCEPTION
    WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spPlayersDelete;
--------------------------------------------------------------------------------

-------------------------- TEST spPlayersDelete --------------------------------
DECLARE
    v_result NUMBER;

BEGIN

    spPlayersDelete(2323743,v_result);
    
    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Delete failed.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Delete successful for Player ID: ' || v_result);
    END IF;
    
END;
--------------------------------------------------------------------------------

--Object 4 : spPlayersSelect
-- SELECT return all fields in a single row from a table given a PK value
CREATE OR REPLACE PROCEDURE spPlayersSelect(
    p_playerId NUMBER,
    out_regnumber OUT VARCHAR2,
    out_lastname OUT VARCHAR2,
    out_firstname OUT VARCHAR2,
    out_isactive OUT NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
    -- Check if the primary key is valid
    IF p_playerId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;
    ELSE
        -- Select data from the table
            SELECT regnumber, lastname, firstname, isactive
            INTO out_regnumber, out_lastname, out_firstname, out_isactive
            FROM players
            WHERE playerid = p_playerId;
             
        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE           
            -- Rows were affected, indicating successful deletion
            out_result := p_playerId;          
        END IF;
    
    END IF;
EXCEPTION
   WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spPlayersSelect;
--------------------------------------------------------------------------------
---------------------------- TEST SELECT function------------------------------
DECLARE
    v_regnumber VARCHAR2(50);
    v_lastname VARCHAR2(50);
    v_firstname VARCHAR2(50);
    v_isactive NUMBER;
    v_result NUMBER;

BEGIN
    spPlayersSelect(1302,v_regnumber,v_lastname,v_firstname,v_isactive,v_result);

    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Select failed or Player ID not found.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Select successful for Player ID: ' || v_result);
        DBMS_OUTPUT.PUT_LINE('RegNumber: ' || v_regnumber);
        DBMS_OUTPUT.PUT_LINE('LastName: ' || v_lastname);
        DBMS_OUTPUT.PUT_LINE('FirstName: ' || v_firstname);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || v_isactive);
    END IF;
END;
--------------------------------------------------------------------------------



--Object 5 : spTeamInsert
CREATE OR REPLACE PROCEDURE spTeamInsert(
    t_teamId NUMBER,
    t_teamName VARCHAR2,
    t_isActive NUMBER,
    t_jerseyColor VARCHAR2,
    out_result OUT NUMBER
)
AS
BEGIN

     IF t_teamId <= 0 THEN
        -- Raise an exception for an invalid primary key
         out_result := -1;
    ELSE
        -- Insert data into the table
        INSERT INTO teams
        VALUES (t_teamId, t_teamName, t_isActive,t_jerseyColor);
        
        -- Check if any rows were affected, -- check duplicate row
        IF SQL%ROWCOUNT = 1 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE           
            -- Rows were affected, indicating successful deletion
            out_result := t_teamId;          
        END IF;
    
    END IF;

    COMMIT;
EXCEPTION
  WHEN OTHERS THEN out_result := -1; ROLLBACK;       
END spTeamInsert;

--------------------------------------------------------------------------------


---------------------------- TEST spTeamInsert --------------------------------
DECLARE
    out_pk NUMBER;
    
BEGIN
    spTeamInsert(231,'Liverpool',1, 'Red',out_pk);
    
        IF out_pk = -1 THEN
                DBMS_OUTPUT.PUT_LINE('Insertion failed.');
            ELSE
                DBMS_OUTPUT.PUT_LINE('Insert a new team ID: '||out_pk);
        END IF;
END;
----------------------------------------------------------------------------------

---Object 6 : spTeamsUpdate
CREATE OR REPLACE PROCEDURE spTeamsUpdate(
    t_teamId NUMBER,
    t_teamName VARCHAR2,
    t_isActive NUMBER,
    t_jerseyColour VARCHAR2,
    out_result OUT NUMBER
)
AS
BEGIN
    -- Check if the primary key is valid
    IF t_teamId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;
        ROLLBACK;
    ELSE 
       -- Update data in the table
        UPDATE teams
        SET teamname = t_teamName,
            isactive = t_isActive,
            jerseycolour = t_jerseyColour
        WHERE teamid = t_teamId;
                
        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
        ELSE -- found data            
            -- Rows were affected, indicating successful update
            out_result := t_teamId;          
        END IF;
    
    END IF;
    
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spTeamsUpdate;

----------------------------------------------------------------------------------


-------------------------- TEST spPlayersUpdate --------------------------------
DECLARE
    v_result NUMBER;

BEGIN
    spTeamsUpdate(230,'Man City',1,'Blue',v_result);

    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Update failed.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Update successful for team ID: ' || v_result);
    END IF;
END;
----------------------------------------------------------------------------------


---Object 7 : spTeamsDelete
CREATE OR REPLACE PROCEDURE spTeamsDelete(
    p_teamId NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
      -- Check if the primary key is valid
    IF p_teamId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;     
    ELSE   
    
        DELETE FROM teams WHERE teamid = p_teamId;

        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;         
        ELSE      
              -- Rows were affected, indicating successful deletion
            out_result := p_teamId;  
                          
        END IF;
        
    END IF;

    COMMIT;
EXCEPTION
    WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spTeamsDelete;
--------------------------------------------------------------------------------

--------------------------Test spTeamsDelete------------------------------------
DECLARE
    v_result NUMBER;

BEGIN

    spTeamsDelete(230,v_result);
    
    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Delete failed.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Delete successful for Team ID: ' || v_result);
    END IF;

END;
--------------------------------------------------------------------------------
    
    
    
---Object 8 : spTeamsSelect
-- SELECT return all fields in a single row from a table given a PK value
CREATE OR REPLACE PROCEDURE spTeamsSelect(
    t_teamId NUMBER,
    out_teamName OUT VARCHAR2,
    out_isActive OUT NUMBER,
    out_jerseyColour OUT VARCHAR2,
    out_result OUT NUMBER
)
AS
BEGIN
    -- Check if the primary key is valid
    IF t_teamId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;
    ELSE
        -- Select data from the table
            SELECT teamname, isactive, jerseycolour
            INTO out_teamName, out_isActive, out_jerseyColour
            FROM teams
            WHERE teamid = t_teamId;
             
        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE           
            -- Rows were affected, indicating successful deletion
            out_result := t_teamId;          
        END IF;
    
    END IF;
EXCEPTION
    WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spTeamsSelect;
--------------------------------------------------------------------------------
---------------------------- TEST spTeamsSelect function------------------------
DECLARE
    v_teamName VARCHAR2(50);
    v_isActive NUMBER;
    v_jerseyColour VARCHAR2(50);
    v_result  NUMBER;
BEGIN
    spTeamsSelect(210,v_teamName,v_isActive,v_jerseyColour,v_result);

    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Select failed or Team ID not found.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Select successful for Team ID: ' || v_result);
        DBMS_OUTPUT.PUT_LINE('Team name: ' || v_teamName);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || v_isActive);
        DBMS_OUTPUT.PUT_LINE('Jersey colour: ' || v_jerseyColour);     
    END IF;
END;    

--------------------------------------------------------------------------------


------------------------- CRUD FOR Rosters table -------------------------------

--Object 9 : spRosterInsert
CREATE OR REPLACE PROCEDURE spRosterInsert(
    r_playerid NUMBER,
    r_teamId NUMBER,
    r_isactive NUMBER,
    r_jerseyNumber NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN

     IF r_playerid <= 0 THEN
        -- Raise an exception for an invalid primary key
         out_result := -1;
    ELSE

        -- Insert data into the table
        INSERT INTO rosters(playerid, teamid, isactive, jerseynumber)
        VALUES (r_playerid, r_teamId, r_isactive,r_jerseyNumber);
               
        -- Check if any rows were affected, -- check duplicate row
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE           
            -- Rows were affected, indicating successful deletion
            out_result := r_playerid;          
        END IF;
    
    END IF;

    COMMIT;
EXCEPTION
WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spRosterInsert;

--------------------------------------------------------------------------------


---------------------------- TEST spTeamInsert --------------------------------
DECLARE
    out_pk NUMBER;
    
BEGIN
    spRosterInsert(2323743,223,1,10,out_pk);
    
        IF out_pk = -1 THEN
                DBMS_OUTPUT.PUT_LINE('Insertion failed.');
            ELSE
                DBMS_OUTPUT.PUT_LINE('Insert a new roster for player id: '||out_pk);
                
            END IF;           
END;
----------------------------------------------------------------------------------

--Object 10 : sprRosterUpdate
CREATE OR REPLACE PROCEDURE sprRosterUpdate(
    r_rosterid NUMBER,
    r_playerid NUMBER,
    r_teamId NUMBER,
    r_isactive NUMBER,
    r_jerseyNumber NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
    -- Check if the primary key is valid
    IF r_rosterid <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;
        ROLLBACK;
    ELSE 
       -- Update data in the table
        UPDATE rosters
        SET playerid = r_playerid,
            teamid = r_teamId,
            isactive = r_isactive,
            jerseynumber = r_jerseyNumber          
        WHERE rosterid = r_rosterid;
                
        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
        ELSE -- found data            
            -- Rows were affected, indicating successful update
            out_result := r_rosterid;          
        END IF;
    
    END IF;
    
    COMMIT;
EXCEPTION
WHEN OTHERS THEN out_result := -1; ROLLBACK;
END sprRosterUpdate;

----------------------------------------------------------------------------------


-------------------------- TEST spPlayersUpdate --------------------------------
DECLARE
    v_result NUMBER;

BEGIN
    sprRosterUpdate(230,1150,223,1,27,v_result);

    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Update failed.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Update successful for roster ID: ' || v_result);
    END IF;
END;
--------------------------------------------------------------------------------


--Object 11 : spRostersDelete
CREATE OR REPLACE PROCEDURE spRostersDelete(
    r_rosterId NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
      -- Check if the primary key is valid
    IF r_rosterId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;     
    ELSE   
    
        DELETE FROM rosters WHERE rosterid = r_rosterId;

        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;         
        ELSE      
              -- Rows were affected, indicating successful deletion
            out_result := r_rosterId;  
                          
        END IF;
        
    END IF;

    COMMIT;
EXCEPTION
WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spRostersDelete;
--------------------------------------------------------------------------------

--------------------------Test spTeamsDelete------------------------------------
DECLARE
    v_result NUMBER;

BEGIN

    spRostersDelete(230,v_result);
    
    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Delete failed.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Delete successful for Team ID: ' || v_result);
    END IF;

END;
--------------------------------------------------------------------------------
    


--Object 12 : spRosterSelect
CREATE OR REPLACE PROCEDURE spRosterSelect(
    r_rosterId NUMBER,
    r_playerId OUT NUMBER,
    r_teamId OUT NUMBER,
    r_isactive OUT NUMBER,
    r_jerseyNumber OUT NUMBER,
    out_result OUT NUMBER
)
AS
BEGIN
    -- Check if the primary key is valid
    IF r_rosterId <= 0 THEN
        -- Raise an exception for an invalid primary key
        out_result := -1;
    ELSE
        -- Select data from the table
            SELECT playerid, teamid, isactive,jerseynumber
            INTO r_playerId, r_teamId, r_isactive,r_jerseyNumber
            FROM rosters
            WHERE rosterid = r_rosterId;
             
        -- Check if any rows were affected
        IF SQL%ROWCOUNT = 0 THEN
            -- No rows were found
            out_result := -1;
           
        ELSE           
            -- Rows were affected, indicating successful deletion
            out_result := r_rosterId;          
        END IF;
    
    END IF;
EXCEPTION
WHEN OTHERS THEN out_result := -1; ROLLBACK;
END spRosterSelect;
--------------------------------------------------------------------------------
---------------------------- TEST spTeamsSelect function------------------------
DECLARE
    v_rosterid NUMBER;
    v_playerid NUMBER;
    v_teamid NUMBER;
    v_isactive NUMBER;
    v_jerseyNumber NUMBER;
    v_result  NUMBER;
BEGIN
    spRosterSelect(254,v_playerid,v_teamid,v_isactive,v_jerseyNumber,v_result);

    -- Check the result
    IF v_result = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Select failed or Team ID not found.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Select successful for Roster ID: ' || v_result);
        DBMS_OUTPUT.PUT_LINE('Player id: ' || v_playerid);
        DBMS_OUTPUT.PUT_LINE('Team id: ' || v_teamid);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || v_isactive);
        DBMS_OUTPUT.PUT_LINE('Jersey Number: ' || v_jerseyNumber);     
    END IF;

END;    

--------------------------------------------------------------------------------


--Object 13: spPlayersSelectAll
CREATE OR REPLACE PROCEDURE spPlayersSelectAll
AS
BEGIN
    FOR player_rec IN (SELECT * FROM players)
    LOOP
        DBMS_OUTPUT.PUT_LINE('Player ID: ' || player_rec.playerid);
        DBMS_OUTPUT.PUT_LINE('RegNumber: ' || player_rec.regnumber);
        DBMS_OUTPUT.PUT_LINE('LastName: ' || player_rec.lastname);
        DBMS_OUTPUT.PUT_LINE('FirstName: ' || player_rec.firstname);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || player_rec.isactive);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('No data found in Players table.');
END spPlayersSelectAll;


--Object 14: spTeamsSelectAll
CREATE OR REPLACE PROCEDURE spTeamsSelectAll
AS
BEGIN
    FOR team_rec IN (SELECT * FROM teams)
    LOOP
        DBMS_OUTPUT.PUT_LINE('Team ID: ' || team_rec.teamid);
        DBMS_OUTPUT.PUT_LINE('Team Name: ' || team_rec.teamname);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || team_rec.isactive);
        DBMS_OUTPUT.PUT_LINE('Jersey Colour: ' || team_rec.jerseycolour);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('No data found in Teams table.');
END spTeamsSelectAll;


-- Object 15: spRostersSelectAll
CREATE OR REPLACE PROCEDURE spRostersSelectAll
AS
BEGIN
    FOR roster_rec IN (SELECT * FROM rosters)
    LOOP
        DBMS_OUTPUT.PUT_LINE('Roster ID: ' || roster_rec.rosterid);
        DBMS_OUTPUT.PUT_LINE('Player ID: ' || roster_rec.playerid);
        DBMS_OUTPUT.PUT_LINE('Team ID: ' || roster_rec.teamid);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || roster_rec.isactive);
        DBMS_OUTPUT.PUT_LINE('Jersey Number: ' || roster_rec.jerseynumber);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('No data found in Rosters table.');
END spRostersSelectAll;

-- Test spPlayersSelectAll
BEGIN
    spPlayersSelectAll; 
END;

-- Test spTeamsSelectAll
BEGIN    
    spTeamsSelectAll;
END;

-- Test spRostersSelectAll
BEGIN
    spRostersSelectAll;
END;

-- Object 16: spPlayersSelectAll (Opional)
CREATE OR REPLACE PROCEDURE spPlayersSelectAll(
    p_result OUT SYS_REFCURSOR
)
AS
BEGIN
    OPEN p_result FOR
        SELECT * FROM players;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('No data found in the table.');
END spPlayersSelectAll;

--------------------------- Test spPlayersSelectAll ----------------------------
DECLARE
    v_player_id NUMBER;
    v_reg_number VARCHAR2(50);
    v_last_name VARCHAR2(50);
    v_first_name VARCHAR2(50);
    v_is_active NUMBER;
    v_result SYS_REFCURSOR;
BEGIN
    -- Call the stored procedure
    spPlayersSelectAll(p_result => v_result);

    -- Fetch the result set
    LOOP
        FETCH v_result 
        INTO v_player_id, 
             v_reg_number, 
             v_last_name, 
             v_first_name, 
             v_is_active;
        EXIT WHEN v_result%NOTFOUND;

        -- Output the fetched data to the script window
        DBMS_OUTPUT.PUT_LINE('Player ID: ' || v_player_id);
        DBMS_OUTPUT.PUT_LINE('RegNumber: ' || v_reg_number);
        DBMS_OUTPUT.PUT_LINE('LastName: ' || v_last_name);
        DBMS_OUTPUT.PUT_LINE('FirstName: ' || v_first_name);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || v_is_active);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
    -- Close the cursor
    CLOSE v_result;
END;
---------------------------------------------------------------------------------

---Object 17: spTeamsSelectAll (Opional)
CREATE OR REPLACE PROCEDURE spTeamsSelectAll(
    t_result OUT SYS_REFCURSOR
)
AS
BEGIN
    OPEN t_result FOR
        SELECT * FROM teams;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('No data found in the table.');
END spTeamsSelectAll;


--------------------------- Test spTeamsSelectAll ----------------------------
DECLARE
    v_team_id NUMBER;
    v_team_name VARCHAR2(50);
    v_is_active NUMBER;
    v_jersey_colour VARCHAR2(50);
    v_result SYS_REFCURSOR;

BEGIN
    -- Call the stored procedure
    spTeamsSelectAll(t_result => v_result);

    -- Fetch the result set
    LOOP
        FETCH v_result 
        INTO v_team_id, 
             v_team_name, 
             v_is_active, 
             v_jersey_colour;
        EXIT WHEN v_result%NOTFOUND;

        -- Output the fetched data to the script window
        DBMS_OUTPUT.PUT_LINE('Team ID: ' || v_team_id);
        DBMS_OUTPUT.PUT_LINE('Team Name: ' || v_team_name);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || v_is_active);
        DBMS_OUTPUT.PUT_LINE('Jersey Colour: ' || v_jersey_colour);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
    -- Close the cursor
    CLOSE v_result;
END;
--------------------------------------------------------------------------------


--Object 18: spRostersSelectAll (Opional)
CREATE OR REPLACE PROCEDURE spRostersSelectAll(
    r_result OUT SYS_REFCURSOR
)
AS
BEGIN
    OPEN r_result FOR
        SELECT * FROM rosters;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('No data found in the table.');
END spRostersSelectAll;

--------------------------- Test spRostersSelectAll ----------------------------
DECLARE
    v_roster_id NUMBER;
    v_player_id NUMBER;
    v_team_id NUMBER;
    v_is_active NUMBER;
    v_jersey_number NUMBER;
    v_result SYS_REFCURSOR;
BEGIN
    -- Call the stored procedure
    spRostersSelectAll(r_result => v_result);
    -- Fetch the result set
    LOOP
        FETCH v_result 
        INTO v_roster_id, 
             v_player_id, 
             v_team_id, 
             v_is_active, 
             v_jersey_number;
        EXIT WHEN v_result%NOTFOUND;
        -- Output the fetched data to the script window
        DBMS_OUTPUT.PUT_LINE('Roster ID: ' || v_roster_id);
        DBMS_OUTPUT.PUT_LINE('Player ID: ' || v_player_id);
        DBMS_OUTPUT.PUT_LINE('Team ID: ' || v_team_id);
        DBMS_OUTPUT.PUT_LINE('IsActive: ' || v_is_active);
        DBMS_OUTPUT.PUT_LINE('Jersey Number: ' || v_jersey_number);
        DBMS_OUTPUT.PUT_LINE('------------------------');
        DBMS_OUTPUT.PUT_LINE(CHR(10));
    END LOOP;
    CLOSE v_result;
END;
--------------------------------------------------------------------------------


--Object 19: vwPlayerRosters
CREATE OR REPLACE VIEW vwPlayerRosters AS
SELECT
    p.playerid,
    p.regnumber,
    p.lastname,
    p.firstname,
    p.isactive AS player_isactive,
    r.rosterid,
    r.teamid,
    r.isactive AS roster_isactive,
    r.jerseynumber,
    t.teamname,
    t.isactive AS team_isactive,
    t.jerseycolour
FROM
    players p
JOIN
    rosters r ON p.playerid = r.playerid
JOIN
    teams t ON r.teamid = t.teamid;
-------------------------------

--- Test vwPlayerRosters
SELECT * FROM vwPlayerRosters;


--Object 20: spTeamRosterByID
CREATE OR REPLACE PROCEDURE spTeamRosterByID(
    p_teamId NUMBER
)AS
BEGIN
    DECLARE
        v_found BOOLEAN := FALSE;
    BEGIN
        FOR roster_rec IN (SELECT * FROM (vwPlayerRosters) WHERE teamid = p_teamID)
        LOOP
             v_found := TRUE;  -- Set the flag to true if any rows are found
            DBMS_OUTPUT.PUT_LINE('Player ID: ' || roster_rec.playerid);
            DBMS_OUTPUT.PUT_LINE('RegNumber: ' || roster_rec.regnumber);
            DBMS_OUTPUT.PUT_LINE('LastName: ' || roster_rec.lastname);
            DBMS_OUTPUT.PUT_LINE('FirstName: ' || roster_rec.firstname);
            DBMS_OUTPUT.PUT_LINE('IsActive (Player): ' || roster_rec.player_isactive);
            DBMS_OUTPUT.PUT_LINE('Roster ID: ' || roster_rec.rosterid);
            DBMS_OUTPUT.PUT_LINE('IsActive (Roster): ' || roster_rec.roster_isactive);
            DBMS_OUTPUT.PUT_LINE('Jersey Number: ' || roster_rec.jerseynumber);
            DBMS_OUTPUT.PUT_LINE('Team Name: ' || roster_rec.teamname);
            DBMS_OUTPUT.PUT_LINE('IsActive (Team): ' || roster_rec.team_isactive);
            DBMS_OUTPUT.PUT_LINE('Jersey Colour: ' || roster_rec.jerseycolour);
            DBMS_OUTPUT.PUT_LINE('------------------------');
        END LOOP;
    
         -- If no rows are found, raise a custom error
        IF NOT v_found THEN
            DBMS_OUTPUT.PUT_LINE('No data found in the table.');
        END IF;
        
    END;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('Error! not found data');
END spTeamRosterByID;


--------------------------- Test spTeamRosterByID ------------------------------

BEGIN
    spTeamRosterByID(210);
    spTeamRosterByID(0);
END;



--Object 21: spTeamRosterByName
CREATE OR REPLACE PROCEDURE spTeamRosterByName(
    p_teamName VARCHAR2
)AS
BEGIN
    DECLARE
        v_found BOOLEAN := FALSE;  -- Flag to check if any rows are found
    BEGIN
        FOR roster_rec IN 
        (SELECT * FROM (vwPlayerRosters)WHERE UPPER(teamname) LIKE UPPER('%'||p_teamName||'%'))
        LOOP
            v_found := TRUE;  -- Set the flag to true if any rows are found

            DBMS_OUTPUT.PUT_LINE('Player ID: ' || roster_rec.playerid);
            DBMS_OUTPUT.PUT_LINE('RegNumber: ' || roster_rec.regnumber);
            DBMS_OUTPUT.PUT_LINE('LastName: ' || roster_rec.lastname);
            DBMS_OUTPUT.PUT_LINE('FirstName: ' || roster_rec.firstname);
            DBMS_OUTPUT.PUT_LINE('IsActive (Player): ' || roster_rec.player_isactive);
            DBMS_OUTPUT.PUT_LINE('Roster ID: ' || roster_rec.rosterid);
            DBMS_OUTPUT.PUT_LINE('IsActive (Roster): ' || roster_rec.roster_isactive);
            DBMS_OUTPUT.PUT_LINE('Jersey Number: ' || roster_rec.jerseynumber);
            DBMS_OUTPUT.PUT_LINE('Team Name: ' || roster_rec.teamname);
            DBMS_OUTPUT.PUT_LINE('IsActive (Team): ' || roster_rec.team_isactive);
            DBMS_OUTPUT.PUT_LINE('Jersey Colour: ' || roster_rec.jerseycolour);
            DBMS_OUTPUT.PUT_LINE('------------------------');
        END LOOP;

        -- If no rows are found, raise a custom error
        IF NOT v_found THEN
            DBMS_OUTPUT.PUT_LINE('No data found in the table.');
        END IF;
    END;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- Handle the case where no data is found
        DBMS_OUTPUT.PUT_LINE('Error! not found data');
END spTeamRosterByName;


---------------------- TEST spTeamRosterByName---------------------------------
BEGIN
    spTeamRosterByName('Bo');
    spTeamRosterByName('OO');
END;



-- Object 22: vwTeamsNumPlayers
CREATE OR REPLACE VIEW vwTeamsNumPlayers AS
SELECT
    t.teamid,
    t.teamname,
    COUNT(r.playerid) AS number_players
FROM
    teams t 
    LEFT JOIN rosters r ON t.teamid = r.teamid
AND r.isactive =1
GROUP BY
    t.teamid, t.teamname;
    
-------------------------- Test vwTeamsNumPlayers view -------------------------
SELECT* FROM vwTeamsNumPlayers;


--Object 23: fncNumPlayersByTeamID
CREATE OR REPLACE FUNCTION fncNumPlayersByTeamID(p_teamId NUMBER)
RETURN NUMBER
AS
    v_numPlayers NUMBER; 
BEGIN
    --Get number of players
    SELECT number_players
    INTO v_numPlayers
    FROM vwTeamsNumPlayers WHERE
    teamid = p_teamid;
    
    -- Return the number of players
    RETURN v_numPlayers;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
         -- Return NULL when no data is found
        RETURN NULL;
END fncNumPlayersByTeamID;

---------------------- TEST fncNumPlayersByTeamID-------------------------------
DECLARE
   v_numPlayers NUMBER;
   v_teamId NUMBER;
BEGIN
   v_teamId :=222;
   -- Replace with the actual team ID
   v_numPlayers := fncNumPlayersByTeamID(v_teamId); 

   IF v_numPlayers IS NOT NULL THEN
      DBMS_OUTPUT.PUT_LINE('TeamId:'|| v_teamId||' has ' || 
                            v_numPlayers ||' players.');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Team not found.');
   END IF;

END;
--------------------------------------------------------------------------------


--Object 24: vwSchedule
CREATE OR REPLACE VIEW vwSchedule AS
SELECT
   g.gameid AS gameid,
   g.gamedatetime AS gamedate,
   h.teamid AS hometeamid,
   h.teamname AS hometeam,
   a.teamid AS awayteamid,
   a.teamname AS awayteam,
   g.locationid,
   l.locationname
FROM
    games g
LEFT JOIN
    teams h ON g.hometeam = h.teamid  
LEFT JOIN
    teams a ON g.visitteam = a.teamid
LEFT JOIN
    sllocations l ON g.locationid=l.locationid;
   
    
-------------------------- Test vwSchedule view --------------------------------    
SELECT* FROM vwSchedule;


  
--Object 25: spSchedUpcomingGames
CREATE OR REPLACE PROCEDURE spSchedUpcomingGames(n IN NUMBER) AS
    v_current_date DATE := SYSDATE;
    v_has_upcoming_games BOOLEAN := FALSE;
BEGIN
    FOR game_rec IN (
        SELECT 
            gameid, 
            gamedatetime
        FROM games
        WHERE gamedatetime BETWEEN v_current_date AND v_current_date + n
    ) LOOP 
        -- Display the upcoming games
        DBMS_OUTPUT.PUT_LINE('Game: ' || game_rec.gameid || ', Date: ' || TO_CHAR(game_rec.gamedatetime, 'MM/DD/YYYY HH24:MI:SS'));
         v_has_upcoming_games := TRUE;
    END LOOP;   
    
   -- If no upcoming games found
    IF NOT v_has_upcoming_games THEN
        DBMS_OUTPUT.PUT_LINE('No upcoming games in the next ' || n || ' days.');
    END IF;
EXCEPTION
    WHEN TOO_MANY_ROWS THEN DBMS_OUTPUT.PUT_LINE('Error! there are too many rows!');
    WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('No upcoming games in the next ' || n || ' days.');
END spSchedUpcomingGames;


--- Test spSchedUpcomingGames
BEGIN
  spSchedUpcomingGames(5); -- Assuming you want to find games in the next 5 days
END;



----Object 26: spSchedPastGames
CREATE OR REPLACE PROCEDURE spSchedPastGames(n IN NUMBER) AS
    v_current_date DATE := SYSDATE;
    v_has_upcoming_games BOOLEAN := FALSE;
BEGIN
    FOR game_rec IN (
        SELECT 
            gameid, 
            gamedatetime
        FROM games
        WHERE gamedatetime BETWEEN v_current_date - n AND v_current_date
    ) LOOP 
        -- Display the past games
        DBMS_OUTPUT.PUT_LINE('Game: ' || game_rec.gameid || ', Date: ' || TO_CHAR(game_rec.gamedatetime, 'MM/DD/YYYY HH24:MI:SS'));
         v_has_upcoming_games := TRUE;
    END LOOP;   
    
     -- If no upcoming games found
    IF NOT v_has_upcoming_games THEN
        DBMS_OUTPUT.PUT_LINE('No upcoming games in the next ' || n || ' days.');
    END IF;
    
EXCEPTION
    WHEN TOO_MANY_ROWS THEN DBMS_OUTPUT.PUT_LINE('Error! there are too many rows!');
    WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('No upcoming games in the next ' || n || ' days.');
END spSchedPastGames;


-- Assuming you want to find games played in the last 7 days
BEGIN
  spSchedPastGames(1); 
END;




-- Object 27: spRunStandings
CREATE OR REPLACE PROCEDURE spRunStandings AS
BEGIN
    -- Delete existing data from standings table
    DELETE FROM tempstandings;

    -- Insert updated standings data
    INSERT INTO tempstandings (
        SELECT 
            TheTeamID,
            (SELECT teamname FROM teams WHERE teamid = t.TheTeamID) AS teamname,
            SUM(GamesPlayed) AS GP,
            SUM(Wins) AS W,
            SUM(Losses) AS L,
            SUM(Ties) AS T,
            SUM(Wins)*3 + SUM(Ties) AS Pts,
            SUM(GoalsFor) AS GF,
            SUM(GoalsAgainst) AS GA,
            SUM(GoalsFor) - SUM(GoalsAgainst) AS GD
        FROM (
            -- from the home team perspective
            SELECT
                hometeam AS TheTeamID,
                COUNT(gameID) AS GamesPlayed,
                SUM(homescore) AS GoalsFor,
                SUM(visitscore) AS GoalsAgainst,
                SUM(
                    CASE
                        WHEN homescore > visitscore THEN 1
                        ELSE 0
                    END
                ) As Wins, 
                SUM(
                    CASE
                        WHEN homescore < visitscore THEN 1
                        ELSE 0
                    END
                ) As Losses,
                SUM(
                    CASE
                        WHEN homescore = visitscore THEN 1
                        ELSE 0
                    END
                ) As Ties    
            FROM games
            WHERE isPlayed = 1
            GROUP BY hometeam
            
            UNION ALL
            
            -- from the perspective of the visiting team
            SELECT
                visitteam AS TheTeamID,
                COUNT(gameID) AS GamesPlayed,
                SUM(visitscore) AS GoalsFor,
                SUM(homescore) AS GoalsAgainst,
                SUM(
                    CASE
                        WHEN homescore < visitscore THEN 1
                        ELSE 0
                    END
                ) As Wins, 
                SUM(
                    CASE
                        WHEN homescore > visitscore THEN 1
                        ELSE 0
                    END
                ) As Losses,
                SUM(
                    CASE
                        WHEN homescore = visitscore THEN 1
                        ELSE 0
                    END
                ) As Ties    
            FROM games
            WHERE isPlayed = 1
            GROUP BY visitteam
        ) t
        GROUP BY TheTeamID
    );
     DBMS_OUTPUT.PUT_LINE('Tempstanding table has been updated!');
     
EXCEPTION
    WHEN TOO_MANY_ROWS THEN DBMS_OUTPUT.PUT_LINE('Error! there are too many rows!');
END spRunStandings;

--------------------------------Test spRunStandings ---------------------------
BEGIN
    spRunStandings;
END;
--------------------------------------------------------------------------------




--Object 28: trgUpdateStandings (Trigger)
CREATE OR REPLACE TRIGGER trgUpdateStandings
AFTER INSERT OR UPDATE OF homescore,isPlayed,visitScore ON games 
BEGIN
    DELETE FROM tempstandings;

    INSERT INTO tempstandings (
    
    SELECT 
        TheTeamID,
        (SELECT teamname FROM teams WHERE teamid = t.TheTeamID) AS teamname,
        SUM(GamesPlayed) AS GP,
        SUM(Wins) AS W,
        SUM(Losses) AS L,
        SUM(Ties) AS T,
        SUM(Wins)*3 + SUM(Ties) AS Pts,
        SUM(GoalsFor) AS GF,
        SUM(GoalsAgainst) AS GA,
        SUM(GoalsFor) - SUM(GoalsAgainst) AS GD
    FROM (
    -- from the home team perspective
        SELECT
            hometeam AS TheTeamID,
            COUNT(gameID) AS GamesPlayed,
            SUM(homescore) AS GoalsFor,
            SUM(visitscore) AS GoalsAgainst,
            SUM(
                CASE
                    WHEN homescore > visitscore THEN 1
                    ELSE 0
                    END
                ) As Wins, 
            SUM(
                CASE
                    WHEN homescore < visitscore THEN 1
                    ELSE 0
                    END
                ) As Losses,
            SUM(
                CASE
                    WHEN homescore = visitscore THEN 1
                    ELSE 0
                    END
                ) As Ties    
        FROM games
        WHERE isPlayed = 1
        GROUP BY hometeam
        
        UNION ALL
        
        -- from the perspective of the visiting team
        SELECT
            visitteam AS TheTeamID,
            COUNT(gameID) AS GamesPlayed,
            SUM(visitscore) AS GoalsFor,
            SUM(homescore) AS GoalsAgainst,
            SUM(
                CASE
                    WHEN homescore < visitscore THEN 1
                    ELSE 0
                    END
                ) As Wins, 
            SUM(
                CASE
                    WHEN homescore > visitscore THEN 1
                    ELSE 0
                    END
                ) As Losses,
            SUM(
                CASE
                    WHEN homescore = visitscore THEN 1
                    ELSE 0
                    END
                ) As Ties    
        FROM games
        WHERE isPlayed = 1
        GROUP BY visitteam ) t
    GROUP BY TheTeamID
    );

END;


-----------------------------Test the triggger -------------------------------------
-- Update scores
-- Game 1
-- hometeam 218 has pts 14 , awayteam 212 has pts 12
UPDATE games SET homescore = 6, visitscore = 1 WHERE gameid = 1;


--Object 29: sp_updateScores
CREATE OR REPLACE PROCEDURE sp_updateScores(
    p_game_id INT,
    p_home_score INT,
    p_visit_score INT
) AS
BEGIN
    -- Update scores for the specified game
    UPDATE games
    SET homescore = p_home_score, visitscore = p_visit_score
    WHERE gameID = p_game_id;
    
    DBMS_OUTPUT.PUT_LINE('Scores updated successfully!');
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error updating scores: ' || SQLERRM);
END sp_updateScores;

--- Test sp_updateScores
BEGIN
    sp_updateScores(21, 5, 1); -- Replace with actual values and game ID
END;

-- Check the standing after update
SELECT* FROM tempstandings
ORDER BY pts DESC, W DESC, GD DESC;

