import gymnasium as gym
import numpy as np
import random
import matplotlib.pyplot as plt
import copy

def evalfitness(chromosome, render_mode=None):
    env = gym.make("HalfCheetah-v5", render_mode=render_mode) 
    observation, info = env.reset()
    episode_reward = 0
    terminated = False
    truncated = False
    keyframe_index = 0
    K = len(chromosome) 
    remaining_steps = int(chromosome[keyframe_index][-1])
    while not (terminated or truncated):
        action = chromosome[keyframe_index][:-1]
        observation, reward, terminated, truncated, info = env.step(action)
        episode_reward += reward
        remaining_steps -= 1
        if remaining_steps <= 0:
            keyframe_index = (keyframe_index + 1) % K
            remaining_steps = int(chromosome[keyframe_index][-1])
    env.close()
    return episode_reward

def initPopulation(populationSize, numKeyframes):
    population = []
    for _ in range(populationSize):
        chromosome = []
        for _ in range(numKeyframes):
            torques = np.random.uniform(-1.0, 1.0, 6)
            duration = np.random.randint(5, 51)
            gene = np.append(torques, duration)
            chromosome.append(gene)
        population.append(chromosome)
    return population

def tourneySelection(population, fitnessScores):
    parentA, parentB = random.sample(range(len(population)), 2)
    if fitnessScores[parentA] > fitnessScores[parentB]:
        return population[parentA]
    else:
        return population[parentB]

def crossover(parent1, parent2):
    K_len = len(parent1)
    cp = random.randint(1, K_len - 1)
    child = parent1[:cp] + parent2[cp:]
    return child

def mutate(chromosome, mutation_rate=0.1):
    if random.random() < mutation_rate:
        randGene = random.randint(0, len(chromosome) - 1)
        randPara = random.randint(0, 6)
        if randPara < 6:
            chromosome[randGene][randPara] = np.random.uniform(-1.0, 1.0)
        else:
            chromosome[randGene][randPara] = np.random.randint(5, 51)
    return chromosome


import copy
import random
import numpy as np
import matplotlib.pyplot as plt

# ... (Previous functions: initPopulation, evalfitness, tourneySelection, crossover, mutate) ...

def main():
    # --- 1. Parameters ---
    populationSize = 20
    nKeyframes = 5
    numGenerations = 100
    numOffspring = 10
    
    # --- 2. Initial Setup ---
    P1 = initPopulation(populationSize, nKeyframes)
    print("Evaluating initial population...")
    fitnessScores = [evalfitness(chrom, render_mode=None) for chrom in P1]
    rewardsHistory = []

    # --- 3. The Evolutionary Loop ---
    for gen in range(numGenerations):
        newChildren = []
        
        # Breed new offspring
        for _ in range(numOffspring):
            p1 = tourneySelection(P1, fitnessScores)
            p2 = tourneySelection(P1, fitnessScores)
            # Use deepcopy to avoid modifying parents
            child = mutate(copy.deepcopy(crossover(p1, p2)))
            newChildren.append(child)
        
        # Evaluate child fitness
        childScores = [evalfitness(c, render_mode=None) for c in newChildren]
        
        # Combine everything into a pool of 30
        totalPool = P1 + newChildren
        totalScores = fitnessScores + childScores
        
        # --- SURVIVOR SELECTION (TOURNAMENT STYLE) ---
        nextGenP1 = []
        while len(nextGenP1) < populationSize:
            # Re-use tournament selection to pick survivors for the next generation
            survivor = tourneySelection(totalPool, totalScores)
            nextGenP1.append(copy.deepcopy(survivor))

        # Update the population for the next iteration
        P1 = nextGenP1
        
        # Re-calculate fitness scores for the new population
        fitnessScores = [evalfitness(chrom, render_mode=None) for chrom in P1]
        
        # Track the best performance in this generation
        bestGenReward = max(fitnessScores)
        rewardsHistory.append(bestGenReward)
        print(f"Generation {gen}: Best Reward = {bestGenReward}")

    # --- 4. Final Outputs (Animation, File, Plot) ---
    print("Optimization Complete.")
    
    # Find the best cheetah in the final population
    bestIndex = np.argmax(fitnessScores)
    bestCheetah = P1[bestIndex]
    
    print("Showing the best cheetah animation...")
    evalfitness(bestCheetah, render_mode="human")

    # Save to text file
    with open("best_keyframes.txt", "w") as f:
        f.write(f"{len(bestCheetah)}\n")
        for keyframe in bestCheetah:
            line = ", ".join([f"{val:.2f}" if i < 6 else f"{int(val)}" 
                             for i, val in enumerate(keyframe)])
            f.write(line + "\n")
    print("Best keyframes saved to 'best_keyframes.txt'!")

    # Plot the results
    plt.figure(figsize=(10, 5))
    plt.plot(range(numGenerations), rewardsHistory, marker='o', color='g')
    plt.title("Tournament Parents + Tournament Survivors")
    plt.xlabel("Generation")
    plt.ylabel("Best Episode Reward")
    plt.grid(True)
    plt.savefig("tournament+tournament.png")
    plt.show()
    print("Deliverable 4: Convergence plot generated.")

if __name__ == "__main__":
    main()