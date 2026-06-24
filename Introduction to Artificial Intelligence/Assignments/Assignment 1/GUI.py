import streamlit as st
import time
import numpy as np
from A1 import (load_embeddings, WordLadderProblem, 
                               breadth_first_graph_search, depth_first_graph_search, 
                               uniform_cost_search, greedy_best_first_search, a_star_search)
st.set_page_config(page_title="IBA AI: Word Ladder Search", layout="centered")
st.title("🔤 Semantic Word-Ladder Explorer")
st.write("If you can see this, the GUI is working!")
st.markdown("Interact with search algorithms in the GloVe 100d space.")
@st.cache_resource 
def get_data():
    return load_embeddings('glove.100d.20000.txt')
try:
    e_dict, v_list, v_matrix = get_data()
except Exception as e:
    st.error("Could not load GloVe file. Make sure 'glove.100d.20000.txt' is in this folder.")
    st.stop()
st.sidebar.header("Settings")
start_word = st.sidebar.text_input("Start Word", value="panah").lower().strip()
goal_word = st.sidebar.text_input("Goal Word", value="haloze").lower().strip()
algo_name = st.sidebar.selectbox(
    "Choose Algorithm",
    ("BFS", "DFS", "UCS", "Greedy Best-First", "A* Search")
)
k_value = st.sidebar.slider("Number of Neighbors (k)", 1, 50, 20)
algo_map = {
    "BFS": breadth_first_graph_search,
    "DFS": depth_first_graph_search,
    "UCS": uniform_cost_search,
    "Greedy Best-First": greedy_best_first_search,
    "A* Search": a_star_search
}
if st.sidebar.button("Execute Search"):
    if start_word not in e_dict or goal_word not in e_dict:
        missing = start_word if start_word not in e_dict else goal_word
        st.error(f"❌ '{missing}' is not in the vocabulary. Please try another word.")
    else:
        with st.spinner(f'Running {algo_name}...'):
            prob = WordLadderProblem(start_word, goal_word, e_dict, v_matrix, v_list)
            start_time = time.time()
            path, expanded = algo_map[algo_name](prob, k_value)
            end_time = time.time()
            duration = end_time - start_time
        if path:
            st.success("Path Found!")
            m1, m2, m3 = st.columns(3)
            m1.metric("Path Length", len(path))
            m2.metric("Nodes Expanded", expanded)
            m3.metric("Time", f"{duration:.4f}s")
            st.subheader("Resulting Ladder:")
            st.code(" → ".join(path))
        else:
            st.warning("No path found.")
            st.info(f"Nodes Expanded: {expanded}")