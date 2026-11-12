# Lab 2: Architectural Design and Software Detailed Design

This lab is designed to help you understand the concepts of software architecture and detailed design.

🟢 __Simple__: A guided software engineering activity that introduces the basic concepts step by step. It should not take more than 15 - 20 minutes to finish.

🟡 __Moderate__: A software engineering activity that asks you to apply the concepts to a realistic team or project situation. These tasks can usually be completed in about 30 - 45 minutes, depending on your prior knowledge.

🔴 __Complex__: A more demanding or longer software engineering activity that requires you to combine concepts, make decisions as a team, and work through a broader project context. Such tasks might take up to a few hours to complete.


## 🟢 Section I: UML Use-Case Diagrams

In this exercise, you will practice creating a UML use-case diagram from a short system description.
The goal is to identify actors and use-cases, and to model meaningful `include` and `extend` relationships.

### Task Description

Model the following system as a UML use-case diagram in Draw.io.

#### System: Online Pizza Ordering

A small pizza restaurant wants to offer an online ordering system.
Customers can browse the menu, customize a pizza, place an order, pay online, and track the order status.
The kitchen staff prepares accepted orders, and a delivery driver delivers orders that are marked for delivery.

The system should support the following behavior:

* A customer can browse the menu without logging in.
* A customer must log in before placing an order.
* When placing an order, the customer must choose either pickup or delivery.
* Every order must include selecting items from the menu and confirming the order summary.
* If the customer chooses delivery, the system also asks for a delivery address.
* The customer may optionally apply a discount code during checkout.
* The customer pays online after confirming the order.
* Kitchen staff can view new orders and mark an order as being prepared.
* Kitchen staff can mark an order as ready.
* A delivery driver can view orders ready for delivery and mark them as delivered.
* A customer can track the current order status.

#### 1. Identify Actors

Identify all external actors that interact with the online ordering system.

#### 2. Identify Use-Cases

List the main use-cases that should appear in the diagram.

#### 3. Add Relationships

Create the use-case diagram and include at least:

* Two `include` relationships for behavior that is always part of another use-case
* Two `extend` relationships for optional or conditional behavior

Label the actors, use-cases, and relationships clearly.


## 🟢 Section II: UML Sequence Diagrams

In this exercise, you will practice creating a UML sequence diagram from textual requirements.
The goal is to identify the participating actors and system components, model the order of messages, and show important decisions in the interaction.

### Task Description

Model the following system behavior as a UML sequence diagram and model it in Draw.io.

#### System: Library Book Reservation

A university library offers a web application where students can reserve books.
The reservation process should work as follows:

* A student searches for a book by entering a title, author, or ISBN.
* The library web application sends the search request to the library catalog.
* The catalog returns a list of matching books with their availability status.
* The student selects one available book and requests a reservation.
* The web application checks whether the student is logged in.
* The account service verifies that the student has not exceeded the maximum number of active reservations.
* If the account is valid, the web application creates a reservation in the reservation service.
* The reservation service marks the selected book as reserved in the catalog.
* The reservation service sends a confirmation email to the student.
* The web application shows a reservation confirmation with the pickup deadline.
* If the selected book is no longer available, the web application informs the student and asks them to select another book.
* If the account check fails, the web application shows the reason why the reservation cannot be completed.

#### 1. Identify Participants

Identify the actors and system components that should appear as lifelines in your sequence diagram.

#### 2. Model the Main Success Scenario

Create a sequence diagram for the successful reservation of an available book by a student with a valid account.


#### 3. Add Alternatives

Extend your diagram with alternative paths.

* The selected book is no longer available
* The student's account check fails

Use UML combined fragments.


## 🟢 Section III: Layered Architecture

In this exercise, you will apply the idea of layered architecture to a familiar system.
The goal is to decide which responsibilities belong in which layer and to reason about the dependencies between layers.

### Task Description

Design a layered architecture for the following system.

#### System: Simple Online Shop

You are designing a simple online shop.
The system must:

* Display products with current availability
* Allow users to place orders
* Calculate prices, discounts, tax, and shipping costs
* Validate whether enough stock is available before confirming an order
* Store products, orders, customers, and payments in a database
* Send an order confirmation after successful checkout
* Allow administrators to update product data

#### 1. Design the Layers

Create a layered architecture.
For each layer, describe its main responsibility and assign the features above to the correct layer.

E.g.:
* Which layer should contain business rules such as discount calculation and stock validation?
* Which layer should communicate with the database?
* ...

#### 2. Draw Dependencies

Draw the allowed dependencies between the layers.

#### 3. Reflect on the Design

Answer the following questions:

* Would you choose closed or open layering?
* What is one benefit of your design?
* What is one drawback of your design?
* A teammate suggests that the product page should directly query the database because it would be faster. Do you agree? Explain your decision using layered architecture.


## 🟡 Section IV: UML Component Diagrams

In this exercise, you will practice creating a UML component diagram from a short architectural description.
The goal is to identify software components, their interfaces, and the dependencies between them.

### Task Description

Model the following system as a UML component diagram in Draw.io.

#### System: Campus Event Management Platform

A university wants to build a campus event management platform.
Students can browse upcoming events, register for events, receive notifications, and cancel registrations.
Event organizers can create events, update event details, view attendee lists, and check students in at the event.
Administrators can approve new events before they are published.

Students access the platform through a Web Frontend or a Mobile App.
Both clients communicate with an Event Management Service to browse event information.
Event organizers also use the Event Management Service to create events, update event details, view attendee lists, and check students in at the event.
The Event Management Service stores and reads event data from an Event Database and can request calendar entries from an External Calendar Service.

Event registrations are handled by a separate Registration Service.
When a student registers for or cancels an event, the Registration Service checks the student's login status through a User Account Service.
It then stores registration data in the Event Database.

Before an event becomes visible to students, an administrator must approve it through an Approval Service.
After a successful registration or cancellation, a Notification Service sends a message to the student through an External Email Gateway.

The backend services use a shared configuration artifact named `campus-events-config.yaml`.
This configuration file contains the database connection name, the endpoint of the User Account Service, the endpoint of the External Email Gateway, and the endpoint of the External Calendar Service.
The Event Management Service, Registration Service, and Notification Service read this configuration file when they start.

#### 1. Identify Components

Identify the software components described in the scenario that should appear in the component diagram and add them to your diagram.

#### 2. Define Interfaces

Add provided and required interfaces for the most important interactions to your diagram.

#### 3. Draw Dependencies

Show the dependencies between components in your diagram.

Use cylinders for databases even if they are not standard UML components.


## 🔴 Section V: Timing Analysis of an Embedded Controller

In this exercise, you will determine execution times, calculate CPU utilization, verify deadlines, and propose architectural improvements.
The challenge is to distinguish sufficient processing capacity from actually meeting deadlines.

### Task Description

#### System: Greenhouse Climate Controller

A greenhouse controller reads environmental sensors, calculates ventilation commands, checks measurements for plausibility, updates a local display, and records diagnostic information.
All five tasks execute on a single CPU.
Sensor readings, control calculations, and plausibility checks have strict timing requirements; delayed display updates and diagnostics are less urgent, but still have deadlines.

Use the following timing model:

* Each task releases its first job at `t = 0`, then releases another job every period `T`.
* A job's absolute deadline is its release time plus its relative deadline `D`. Completing exactly at the deadline is acceptable.
* The scheduler always selects the ready job with the highest priority. Priority 1 is the highest priority.
* Execution is **non-preemptive**: once a job starts, it runs to completion, even if a higher-priority job becomes ready.
* Whenever a job finishes, the scheduler chooses the highest-priority job that is ready, including jobs released at that exact moment. The CPU is idle only when no job is ready.
* Jobs that miss a deadline are still completed. Jobs of the same task are processed in release order.
* Tasks do not wait for one another, perform blocking I/O, or share locks. All listed operations consume CPU time. Ignore scheduling and context-switch overhead.
* For the schedule, assume every job takes its WCET. The controller is initially idle, with no unfinished jobs from before `t = 0`.

#### Timing Data

All times are in milliseconds. The execution-time descriptions give upper bounds for the individual operations.
Operations listed together execute sequentially unless explicitly described as alternatives.

| Task | Priority | Period `T` | Relative deadline `D` | Execution-time description |
| --- | --- | --- | --- | --- |
| Read Sensors | 1 | 10 | 4 | Initialization: 0.2 ms; then read four sensor channels at 0.2 ms per channel |
| Calculate Control | 2 | 10 | 7 | Preparation: 0.5 ms; then five calculation steps at 0.4 ms per step |
| Check Plausibility | 3 | 20 | 10 | Setup: 0.3 ms; then three checks at 0.4 ms per check |
| Update Display | 4 | 40 | 40 | Prepare the frame: 0.8 ms; then render eight fields at 0.4 ms per field |
| Record Diagnostics | 5 | 100 | 100 | Collect data: 1 ms; then **either** normal processing: 2 ms, **or** recovery processing: 5 ms |

Normal and recovery processing are mutually exclusive.
Recovery processing can occur in any diagnostic job, including consecutive jobs.
Do not assume that an uncommon execution path can be ignored.

#### 1. Determine WCET and CPU Utilization

Determine the WCET `C` of each task and its activation frequency in Hz.
Then calculate each task's CPU utilization and the total CPU utilization using `U_i = C_i / T_i`.

| Task | WCET `C` [ms] | Frequency [Hz] | Utilization [%] |
| --- | --- | --- | --- |
| Read Sensors | | | |
| Calculate Control | | | |
| Check Plausibility | | | |
| Update Display | | | |
| Record Diagnostics | | | |
| **Total** | — | — | |

A teammate argues: “The total utilization is below 100%, and every task's WCET is shorter than its deadline. Therefore, all deadlines are guaranteed.”
Assess this claim. State what these two checks establish and what still needs to be verified.

#### 2. Construct the Schedule and Verify Deadlines

Draw a CPU timeline for `0 <= t < 40 ms`, showing job releases, execution intervals, and idle intervals.
Include every job released in this interval, and mark its deadline.

For each job, determine its completion time and response time, where response time is measured from release to completion.
Identify every deadline miss in this interval and calculate how late the job finishes.

| Task / job release | Absolute deadline [ms] | Start [ms] | Completion [ms] | Response time [ms] | Deadline met? |
| --- | --- | --- | --- | --- | --- |
| | | | | | |

Explain the cause of any deadline misses using specific intervals from your timeline.

#### 3. Refine the Architecture

Propose one architectural or scheduling change that resolves the deadline misses identified in Task 2.
For example, you could split long-running work into smaller chunks or introduce preemptive scheduling.
Keep all five tasks, their total WCETs, periods, and deadlines unchanged. Keep the simultaneous releases at `t = 0`.

* Describe your change and explain how it allows urgent jobs to run sooner.
* Draw the revised CPU timeline for `0 <= t < 40 ms` and verify that every job released in this interval meets its deadline.
* State whether CPU utilization changes and explain one tradeoff of your design.
