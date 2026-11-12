# Section I Solution: Software Development Process Models

This is one possible solution. Other reasonable answers are possible if they are explained consistently.

## 1. Software Development Life Cycle

| Activity | SDLC phase |
| --- | --- |
| C. The project team determines what functionality students need. | Requirements Engineering |
| E. Software architects define the components and interfaces of the system. | Design |
| A. Developers implement the connection search algorithm. | Implementation |
| G. Testers check whether the complete application fulfills its specified requirements. | (System) Testing |
| B. Students test whether the application satisfies their expectations. | Acceptance Testing |
| D. The application is released to the university app store. | Deployment & Maintenance |
| F. Developers fix defects and adapt the application after its release. | Deployment &Maintenance |

A reasonable order is:

```text
C -> E -> A -> G -> B -> D -> F
```

Typical artifacts:

| Activity | Example artifact |
| --- | --- |
| Requirements Engineering | Requirements specification, user stories, use case model |
| Design | Architecture diagram, component diagram, interface specification |
| Implementation | Source code, executable build, code documentation |
| Testing | Test plan, test cases, defect report, test report |

## 2. Waterfall Model

Simplified Waterfall Model:

```text
Requirements
    -> Design
        -> Implementation
            -> Testing
                -> Deployment
                    -> Maintenance
```

Major activities:

| Waterfall phase | Campus Mobility App activity |
| --- | --- |
| Requirements | Determine needed mobility functions |
| Design | Define app architecture, components, interfaces, data model |
| Implementation | Program timetable, search, notifications, and favorites |
| Testing | Verify features against the specification |
| Deployment | Publish the app to the university app store |
| Maintenance | Fix defects and adapt the app after release |

The Waterfall Model could work well if the university already knows exactly what the app should do, because each phase can be planned, documented, reviewed, and completed before the next phase starts.

The late request for public transport integration is problematic because requirements and design are supposed to be mostly finished before implementation. The change may affect architecture, data sources, interfaces, search logic, tests, schedule, and budget.

Advantages:

* Clear phase structure and documentation
* Easier planning when requirements are stable

Disadvantages:

* Late changes are expensive and difficult
* Useful software is delivered late, so feedback also arrives late

## 3. V-Model

Simplified V-Model:

```text
Requirements Specification        Acceptance Testing
        System Design          System Testing
   Software / Component Design Integration Testing
              Implementation Unit Testing
```

Correspondence:

| Development activity | Corresponding test level |
| --- | --- |
| Requirements Specification | Acceptance Testing |
| System Design | System Testing |
| Software / Component Design | Integration Testing |
| Implementation | Unit Testing |

The connection between the two sides of the V means that test planning is linked to development artifacts. Each test level checks whether the result satisfies the corresponding specification or design level.

## 4. Iterative and Incremental Development

One possible set of increments:

| Increment | Functionality | Why it is useful |
| --- | --- | --- |
| 1 | Shuttle timetable, basic connection search | Students can already see shuttle options and plan trips between university locations. |
| 2 | Delay notifications, favorites | Students get more reliable travel information and can quickly access common routes. |
| 3 | Bicycle sharing, public transport integration, parking information | The app becomes a broader campus mobility platform. |

An increment adds usable functionality to the product. An iteration is a repeated development cycle in which the team plans, builds, tests, and improves the product or part of the product.

The connection search example is primarily iterative development, because the same feature is improved across several versions. It also has an incremental aspect when public transport adds new externally visible capability, but the main focus is refinement of one existing feature.

## 5. Spiral Model

The Spiral Model is suitable because the delay prediction feature has significant uncertainty and technical risk. The team should not commit to a full implementation before investigating whether live GPS data and machine learning can produce useful predictions.

Project risks:

* GPS data may be inaccurate, incomplete, delayed, or inconsistent.
* The prediction model may not be accurate enough to be useful for students.

Example early spiral:

The team could collect a small sample of GPS and historical shuttle delay data, build a prototype prediction model, and compare predicted delays with real delays. The result would show whether the data quality and model accuracy are promising enough for further investment.

Typical activities in one spiral cycle:

| Activity | Explanation |
| --- | --- |
| Determine objectives and alternatives | Define what should be achieved in this cycle and possible solution approaches. |
| Identify and evaluate risks | Analyze technical, cost, schedule, usability, or organizational risks. |
| Develop and verify a prototype or product part | Build enough of the solution to reduce risk and learn from evidence. |
| Plan the next cycle | Decide whether to continue, change direction, or stop based on the results. |

## 6. Identify the Process Model

| Scenario | Process model | Supporting characteristic |
| --- | --- | --- |
| A | V-Model | Every specification level has a corresponding planned test level. |
| B | Iterative / Incremental Development | A usable version is released first, then extended and improved. |
| C | Spiral Model | Prototypes are used to investigate major technical risks. |
| D | Waterfall Model | Requirements, design, implementation, testing, and deployment are performed sequentially from a stable specification. |

## 7. Final Comparison

| Characteristic | Waterfall | V-Model | Iterative / Incremental | Spiral |
| --- | --- | --- | --- | --- |
| Development mainly sequential? | Yes | Yes | No | No |
| Explicit relationship between development and testing? | Limited | Yes | Possible, but not the central feature | Possible, but not the central feature |
| Early delivery of partial functionality possible? | Usually no | Usually no | Yes | Possible |
| Explicit focus on risk analysis? | No | No | Not necessarily | Yes |
| Well suited to changing requirements? | No | Limited | Yes | Yes, especially when changes are risk-driven |
